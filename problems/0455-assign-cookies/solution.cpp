class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int l = 0;
        int r = 0;
        int child = 0;
        while(l<m && r<n){
            if(g[r]<=s[l]){
                child++;
                r++;
                l++;
            }
            else{
                l++;
            }
        }
        return child;
    }
};