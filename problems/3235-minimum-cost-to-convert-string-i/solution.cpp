class Solution {

public:
    vector<int> bfs(int i,
                    unordered_map<char, vector<pair<int, char>>>& adj) {

        priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                       greater<tuple<int, int>>>
            pq;

        pq.push({0, i});
        vector<int> distance(26, INT_MAX);
        distance[i] = 0;
        while (!pq.empty()) {
            auto [w,node] = pq.top();
            pq.pop();
            if(w > distance[node])continue;
            for (auto it : adj[node+'a']) {
                if (w + it.first < distance[it.second - 'a']) {
                    distance[it.second - 'a'] = w + it.first;
                    pq.push({distance[it.second - 'a'], it.second-'a'});
                }
            }
        }
        return distance;
    }

    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<int, char>>> adj;
        for (int i = 0; i < original.size(); i++) {
            char u = original[i];
            char v = changed[i];
            int weight = cost[i];
            adj[u].push_back({weight, v});
        }
        long long ans = 0;
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            dist[i] = bfs(i, adj);
        }

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) {
                continue;
            } 
            if(dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX)return -1;
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        
        return ans;
    }
};