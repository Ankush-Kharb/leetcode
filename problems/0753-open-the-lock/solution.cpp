class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int,string>> pq;

        pq.push({0, "0000"});
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        if(dead.count("0000"))return -1;
        vis.insert("0000");
        while (!pq.empty()) {
            auto [cost, curr] = pq.front();
            pq.pop();
            if (curr == target)
                return cost;
            for (int i = 0; i < 4; i++) {
                string temp = curr;
                temp[i] = (temp[i] - '0' + 1) % 10 + '0';
                string next = temp;
                if (!vis.count(next) && !dead.count(next)) {
                    vis.insert(next);
                    pq.push({cost + 1, next});
                }
                string temp2 = curr;
                temp2[i] = (temp2[i] - '0' + 9) % 10 + '0';
                string prev = temp2;
                if (!vis.count(prev) && !dead.count(prev)) {
                    vis.insert(prev);
                    pq.push({cost + 1, prev});
                }
            }
        }
        return -1;
    }
};