class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())return "";
        int n = strs.size();
        string prefix = strs[0];
        for(int i = 0; i< n ; i++){
            int j = 0;
            while(j<prefix.size() && j<strs[i].size() && prefix[j]==strs[i][j]){
                j++;
            }
            prefix = strs[0].substr(0,j);
        }return prefix;
    }
};