class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> Occur;
        int n = s.size();
        
        for(int i = 0; i < n ; i++){
            if(s[i] == '1'){
                Occur.push_back(i);
            }
        }
        string ans = "";
        int mini = 1e9;
        for(int i = 0 ; i< Occur.size() ; i++){
            int countOne = 0;
            for(int j = i ; j< Occur.size() ; j++){
                countOne++;
                if(countOne == k){
                    int len = Occur[j] - Occur[i] + 1;
                    string temp = s.substr(Occur[i], Occur[j] - Occur[i] + 1);
                    if(mini > len || len == mini && temp < ans){
                        ans = temp;
                        mini = Occur[j] - Occur[i] + 1;
                    }
                    break;
                }
            }
        }
        return ans;
        
    }
};