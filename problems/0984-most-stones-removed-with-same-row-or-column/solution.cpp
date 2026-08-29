class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if (x == parent[x])return x;
        return parent[x] = find(parent[x]);
    }
    void UNION(int x , int y){
        int xP = find(x);
        int yP = find(y);

        if(xP == yP)return ;
        if(rank[xP] > rank[yP]){
            parent[yP] = xP;
        }
        else if(rank[yP] > rank[xP]){
            parent[xP] = yP;
        }
        else {
            parent[xP] = yP;
            rank[yP]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.assign(n,1);
        for(int i = 0 ; i <n ;i++){
            parent[i] = i;
        }
        for(int i = 0 ; i<n  ; i++){
            for(int j = i+1 ; j<n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    UNION(i,j);
                }
            }
        }
        int compos = 0;
        for(int i = 0 ; i<n ; i++){
            if(find(i) == i){
                compos++;
            }
        }
        return n-compos;
    }
};