#!/usr/bin/env python3
"""
Drip-sync LeetCode submissions into this repository.

Two things happen on every run:

  1. NEW solves  - any accepted submission made since the last run is committed
                   straight away, however many there are.
  2. BACKLOG     - problems you had already solved before this repo existed are
                   committed a few at a time (default 5 per run) so the history
                   builds up gradually instead of landing as one huge dump.

The backlog is crawled once on the first run and then stored in
.leetcode-sync-state.json, so later runs only make a handful of API calls.

Requires two env vars (wired up from repo secrets in the workflow):
  LEETCODE_SESSION
  LEETCODE_CSRF_TOKEN
"""

import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

import requests

BASE_URL = "https://leetcode.com"
GRAPHQL_URL = f"{BASE_URL}/graphql/"
STATE_FILE = ".leetcode-sync-state.json"
PAGE_SIZE = 20

LANG_TO_EXT = {
    "bash": "sh", "c": "c", "cpp": "cpp", "csharp": "cs", "dart": "dart",
    "elixir": "ex", "erlang": "erl", "golang": "go", "java": "java",
    "javascript": "js", "kotlin": "kt", "mssql": "sql", "mysql": "sql",
    "oraclesql": "sql", "php": "php", "postgresql": "sql", "python": "py",
    "python3": "py", "pythondata": "py", "racket": "rkt", "ruby": "rb",
    "rust": "rs", "scala": "scala", "swift": "swift", "typescript": "ts",
}


def log(msg):
    print(f"[leetcode-drip] {msg}", flush=True)


# --------------------------------------------------------------------------
# LeetCode API
# --------------------------------------------------------------------------

class LeetCode:
    def __init__(self, session, csrf_token):
        self.headers = {
            "content-type": "application/json",
            "origin": BASE_URL,
            "referer": BASE_URL,
            "cookie": f"csrftoken={csrf_token}; LEETCODE_SESSION={session};",
            "x-csrftoken": csrf_token,
        }

    def _gql(self, query, variables, max_retries=5):
        payload = json.dumps({"query": query, "variables": variables})
        for attempt in range(max_retries + 1):
            try:
                r = requests.post(GRAPHQL_URL, data=payload,
                                  headers=self.headers, timeout=30)
                if r.status_code == 403:
                    raise PermissionError(
                        "LeetCode returned 403. Your LEETCODE_SESSION cookie has "
                        "most likely expired - grab a fresh one and update the "
                        "repo secret."
                    )
                r.raise_for_status()
                body = r.json()
                if body.get("errors"):
                    raise RuntimeError(f"GraphQL error: {body['errors']}")
                return body["data"]
            except PermissionError:
                raise
            except Exception as exc:
                if attempt == max_retries:
                    raise
                wait = 3 ** attempt
                log(f"Request failed ({exc}); retrying in {wait}s")
                time.sleep(wait)

    def submission_page(self, offset, limit=PAGE_SIZE):
        query = """
        query ($offset: Int!, $limit: Int!) {
          submissionList(offset: $offset, limit: $limit) {
            hasNext
            submissions { id lang timestamp statusDisplay runtime memory title titleSlug }
          }
        }"""
        data = self._gql(query, {"offset": offset, "limit": limit})
        return data["submissionList"]

    def submission_details(self, submission_id):
        query = """
        query submissionDetails($submissionId: Int!) {
          submissionDetails(submissionId: $submissionId) {
            runtimePercentile
            memoryPercentile
            code
            question { questionId }
          }
        }"""
        data = self._gql(query, {"submissionId": int(submission_id)})
        return data.get("submissionDetails")

    def question_content(self, title_slug):
        query = """
        query getQuestionDetail($titleSlug: String!) {
          question(titleSlug: $titleSlug) { content difficulty }
        }"""
        try:
            data = self._gql(query, {"titleSlug": title_slug})
            return data.get("question") or {}
        except Exception:
            # Premium-locked problems 403 here; the solution still syncs.
            log(f"Could not fetch description for {title_slug} (locked?)")
            return {}


# --------------------------------------------------------------------------
# State
# --------------------------------------------------------------------------

def load_state(repo_root):
    path = repo_root / STATE_FILE
    if path.exists():
        return json.loads(path.read_text())
    return {"seeded": False, "last_timestamp": 0, "backlog": [], "synced": {}}


def save_state(repo_root, state):
    path = repo_root / STATE_FILE
    path.write_text(json.dumps(state, indent=2, sort_keys=True) + "\n")


# --------------------------------------------------------------------------
# Crawling
# --------------------------------------------------------------------------

def crawl(api, stop_at_timestamp=0, page_delay=1.0):
    """Walk the submission list newest-first, keeping the newest ACCEPTED
    submission per problem. Stops early once submissions are older than
    stop_at_timestamp (0 means crawl everything)."""
    best = {}
    offset = 0
    while True:
        log(f"Fetching submissions, offset {offset}")
        page = api.submission_page(offset)
        subs = page["submissions"]
        if not subs:
            break

        reached_old = False
        for s in subs:
            ts = int(s["timestamp"])
            if stop_at_timestamp and ts <= stop_at_timestamp:
                reached_old = True
                continue
            if s["statusDisplay"] != "Accepted":
                continue
            slug = s["titleSlug"]
            if slug not in best or ts > int(best[slug]["timestamp"]):
                best[slug] = s

        if reached_old or not page["hasNext"]:
            break
        offset += PAGE_SIZE
        time.sleep(page_delay)

    # Oldest first, so the backlog drips out in the order you actually solved them.
    return sorted(best.values(), key=lambda s: int(s["timestamp"]))


# --------------------------------------------------------------------------
# Writing files
# --------------------------------------------------------------------------

def normalize(name):
    return re.sub(r"[^a-zA-Z0-9_-]", "", name.lower().replace(" ", "-"))


def pad(n):
    n = str(n)
    return n if len(n) > 4 else n.rjust(4, "0")


def write_problem(api, repo_root, dest, sub, api_delay=1.0):
    """Fetch code + description for one submission and write it to disk.
    Returns (relative_dir, commit_message) or None if it had to be skipped."""
    details = api.submission_details(sub["id"])
    if not details or not details.get("code"):
        log(f"No code returned for submission {sub['id']} ({sub['titleSlug']}); skipping")
        return None
    time.sleep(api_delay)

    qmeta = api.question_content(sub["titleSlug"])
    time.sleep(api_delay)

    qid = (details.get("question") or {}).get("questionId") or "0"
    folder = f"{pad(qid)}-{normalize(sub['title'])}"
    rel_dir = Path(dest) / folder if dest else Path(folder)
    out_dir = repo_root / rel_dir
    out_dir.mkdir(parents=True, exist_ok=True)

    ext = LANG_TO_EXT.get(sub["lang"], "txt")
    (out_dir / f"solution.{ext}").write_text(details["code"])

    def pct(v):
        return f"{v:.2f}%" if isinstance(v, (int, float)) else "N/A"

    readme = [
        f"# {pad(qid)}. {sub['title']}",
        "",
        f"[View on LeetCode]({BASE_URL}/problems/{sub['titleSlug']}/)",
        "",
    ]
    if qmeta.get("difficulty"):
        readme += [f"**Difficulty:** {qmeta['difficulty']}", ""]
    readme += [
        f"**Language:** {sub['lang']}  ",
        f"**Runtime:** {sub.get('runtime', 'N/A')} (beats {pct(details.get('runtimePercentile'))})  ",
        f"**Memory:** {sub.get('memory', 'N/A')} (beats {pct(details.get('memoryPercentile'))})",
        "",
    ]
    if qmeta.get("content"):
        readme += ["---", "", qmeta["content"], ""]
    (out_dir / "README.md").write_text("\n".join(readme))

    return str(rel_dir), f"{pad(qid)}. {sub['title']} ({sub['lang']})"


# --------------------------------------------------------------------------
# Git
# --------------------------------------------------------------------------

def git(repo_root, *args, check=True):
    return subprocess.run(["git", *args], cwd=repo_root, check=check,
                          capture_output=True, text=True)


def commit(repo_root, paths, message):
    for p in paths:
        git(repo_root, "add", "--", p)
    if not git(repo_root, "diff", "--cached", "--quiet", check=False).returncode:
        log(f"Nothing changed for: {message}")
        return False
    git(repo_root, "commit", "-m", message)
    log(f"Committed: {message}")
    return True


# --------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--per-run", type=int, default=5,
                    help="how many backlog problems to push per run (default 5)")
    ap.add_argument("--dest", default="problems",
                    help="folder inside the repo to write into ('' for root)")
    ap.add_argument("--repo-root", default=".")
    ap.add_argument("--api-delay", type=float, default=1.0,
                    help="seconds to sleep between LeetCode API calls")
    ap.add_argument("--dry-run", action="store_true",
                    help="write files but make no commits")
    args = ap.parse_args()

    session = os.environ.get("LEETCODE_SESSION")
    csrf = os.environ.get("LEETCODE_CSRF_TOKEN")
    if not session or not csrf:
        sys.exit("LEETCODE_SESSION and LEETCODE_CSRF_TOKEN must both be set.")

    repo_root = Path(args.repo_root).resolve()
    state = load_state(repo_root)
    api = LeetCode(session, csrf)

    pushed_any = False

    if not state["seeded"]:
        log("First run - crawling your full submission history to build the backlog.")
        everything = crawl(api)
        state["backlog"] = [
            {k: s[k] for k in ("id", "lang", "timestamp", "runtime", "memory", "title", "titleSlug")}
            for s in everything
        ]
        state["last_timestamp"] = max([int(s["timestamp"]) for s in everything], default=0)
        state["seeded"] = True
        log(f"Backlog seeded with {len(state['backlog'])} problems "
            f"(~{-(-len(state['backlog']) // max(args.per_run, 1))} runs to clear).")
    else:
        log(f"Checking for new solves since timestamp {state['last_timestamp']}")
        fresh = crawl(api, stop_at_timestamp=state["last_timestamp"])
        if fresh:
            log(f"Found {len(fresh)} new accepted submission(s).")
            state["last_timestamp"] = max(int(s["timestamp"]) for s in fresh)
            for sub in fresh:
                # A fresh solve of a backlogged problem supersedes the backlog entry.
                state["backlog"] = [b for b in state["backlog"]
                                    if b["titleSlug"] != sub["titleSlug"]]
                result = write_problem(api, repo_root, args.dest, sub, args.api_delay)
                if not result:
                    continue
                rel_dir, msg = result
                state["synced"][sub["titleSlug"]] = sub["id"]
                if not args.dry_run:
                    save_state(repo_root, state)
                    pushed_any |= commit(repo_root, [rel_dir, STATE_FILE],
                                         f"Solve {msg}")
        else:
            log("No new solves since last run.")

    # Drip the backlog.
    taken = 0
    while taken < args.per_run and state["backlog"]:
        sub = state["backlog"].pop(0)
        if sub["titleSlug"] in state["synced"]:
            continue
        result = write_problem(api, repo_root, args.dest, sub, args.api_delay)
        if not result:
            continue
        rel_dir, msg = result
        state["synced"][sub["titleSlug"]] = sub["id"]
        taken += 1
        if not args.dry_run:
            save_state(repo_root, state)
            pushed_any |= commit(repo_root, [rel_dir, STATE_FILE],
                                 f"Add {msg}")

    if args.dry_run:
        log("Dry run - no commits made.")
        save_state(repo_root, state)
        return

    if not pushed_any:
        # Still record state changes (e.g. seeding) even if no problems moved.
        if commit(repo_root, [STATE_FILE], "Update LeetCode sync state"):
            pushed_any = True

    log(f"Done. {len(state['backlog'])} problem(s) left in the backlog.")


if __name__ == "__main__":
    main()
