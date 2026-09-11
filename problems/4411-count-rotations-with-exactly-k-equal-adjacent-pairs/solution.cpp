class Solution {
public:
    int check(string s){
        int n = s.size();
        int count = 0;
        for(int i = 0 ; i < n-1 ;i++){
            if(s[i] == s[i+1]){
                count++;
            }
        }
        return count;
    }
    string rotate(string s){
        int n = s.size();
        string temp = "";
        for(int i = 1 ; i<n ;i++){
            temp += s[i];
        }
        temp += s[0];
        return temp;
    }
    int countRotations(string s, int k) {
        int ans = 0; 
        for(int i = 0 ; i< s.size() ; i++){
            int score = check(s);
            if(score == k)ans++;
            s = rotate(s);
        }
        return ans;
    }
};