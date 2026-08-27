class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1, 0);
        for (auto it : relations) {
            int u = it[0];
            int v = it[1];
            deg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<int> dist(n+1 , 0);
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                dist[i] = time[i-1];
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans = max(ans , dist[node]);
            for(auto it : adj[node]){
                dist[it] = max(dist[it] , dist[node] + time[it-1]);
                deg[it]--;
                if(deg[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};