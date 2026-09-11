class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> freq(26,0);
        int n = s.size();
        for(auto it : s){
            freq[it - 'a']++;
        }
        
        for(int len = 1 ; len<= n ; len++){
            if(n % len != 0 )continue;
            vector<int> check(26,0);
            for(int i = 0 ; i<len ;i++){
                check[s[i]-'a']++;
            }
            bool ok = true;
            for(int i = len ; i< n ;i+=len){
                vector<int> temp(26,0);
                for(int j = i ; j<i+len ;j++){
                    temp[s[j]-'a']++;
                }
                if(temp != check){
                    ok = false;
                    break;
                }
            }
            if(ok)return len;
        }
        return n;
        
    }
};