class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> deg(n,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            deg[v]++;
        }
        bool found = false;
        int ans = -1;
        for(int i = 0 ; i<n ; i++){ 
            if(deg[i] == 0){
                if(!found){
                ans = i; found = true;}
                else return -1;
            }
        }
        return ans;
    }
};