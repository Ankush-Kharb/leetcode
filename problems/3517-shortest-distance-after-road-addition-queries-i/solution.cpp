class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& nums) {
        vector<vector<int>> dist(n,vector<int>(n));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ;j++){
                if(i == j)dist[i][j]= 0;
                if(i > j )dist[i][j] = -1;
                else{
                    dist[i][j] = j-i;
                }
            }
        }
        vector<int> ans;
        for(auto it : nums){
            int u = it[0];
            int v = it[1];
            dist[u][v] = min(dist[u][v] , 1);
            for(int i = 0 ; i<=u ; i++){
                for(int j = v; j<n ; j++){
                    dist[i][j] = min(dist[i][j] , dist[i][u] + dist[v][j]+1);
                }
            }
            ans.push_back(dist[0][n-1]);
        }
        return ans;
    }
};