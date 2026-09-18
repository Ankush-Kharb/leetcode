class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int n ;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({w, v});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({w, v});
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n, INT_MAX);

        pq.push({0, node1});
        dist[node1] = 0;

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();
            if (node == node2)
                return weight;
            for (auto it : adj[node]) {
                int newW = weight + it.first;
                int newNode = it.second;

                if (newW < dist[newNode]) {
                    dist[newNode] = newW;
                    pq.push({newW, newNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */