class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> mpp;
        int n = routes.size();
        if(source == target)return 0;
        for(int i = 0 ; i < n ; i++){
            for(auto it : routes[i]){
                mpp[it].push_back(i);
            }
        }
        vector<int> vis(n,0);
        queue<pair<int,int>>q;
        int ans = INT_MAX;
        for(auto it : mpp[source]){
            q.push({it,1});
            vis[it] = 1;
        }

        while(!q.empty()){
            int route = q.front().first;
            int number = q.front().second;
            q.pop();
            for(auto it : routes[route]){
                if(it == target){
                    ans = min(ans,number);
                }
                else {
                    for(auto p : mpp[it]){
                        if(vis[p] == 0){
                            q.push({p,number+1});
                            vis[p]=1;
                        }
                    }
                }
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};