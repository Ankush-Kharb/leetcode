class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDeg(n, 0);
        unordered_map<int, vector<int>> adj(n);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDeg[u]++;
            inDeg[v]++;
        }

        int ans = 0;

        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int rank = inDeg[u] + inDeg[v];
                if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
                    rank--;
                }
                 ans = max(ans, rank);
            }  
        }
        return ans;
    }
};