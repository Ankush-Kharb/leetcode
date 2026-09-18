class Solution {
public:
    void dfs(string node , unordered_map<string , vector<string>> &adj ,vector<string> &ans){
        
        sort(adj[node].rbegin(),adj[node].rend());
        while(!adj[node].empty()){
            string next = adj[node].back();
            adj[node].pop_back();
            dfs(next , adj , ans);
        }
        ans.push_back(node);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string , vector<string>> adj;
        for(auto it : tickets){
            adj[it[0]].push_back(it[1]);
        }
        vector<string> ans;
        
         dfs("JFK",adj,ans);
          reverse(ans.begin(),ans.end());
          return ans;
    }
};