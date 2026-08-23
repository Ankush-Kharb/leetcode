# LeetCode

My LeetCode solutions, synced automatically from my LeetCode account.

Each problem lives in `problems/<id>-<slug>/` with the accepted solution and a
README containing the problem statement, difficulty, and runtime/memory stats.

## How the sync works

A [GitHub Actions workflow](.github/workflows/leetcode_drip.yml) runs daily and:

- commits any problem solved since the last run, and
- adds 5 problems from the pre-existing backlog, oldest solved first.

Sync state lives in `.leetcode-sync-state.json`.

### Setup

Two repository secrets are required (Settings -> Secrets and variables -> Actions):

| Secret | Where to find it |
| --- | --- |
| `LEETCODE_SESSION` | leetcode.com cookie `LEETCODE_SESSION` |
| `LEETCODE_CSRF_TOKEN` | leetcode.com cookie `csrftoken` |

`LEETCODE_SESSION` expires every few weeks; refresh the secret when the workflow
starts failing.
