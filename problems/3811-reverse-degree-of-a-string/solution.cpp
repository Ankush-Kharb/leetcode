class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0 ; i< s.size() ;i++){
            int index = i+1;
            int val = 26 - s[i]+'a';
            ans += val*index;

        }
        return ans;
    }
};