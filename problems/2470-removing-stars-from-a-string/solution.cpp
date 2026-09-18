class Solution {
public:
    string removeStars(string s) {
        stack<char> s1;
        string ans;
    int n = s.length();
    int i = 0;
    while(i<n){
        if(s[i]=='*'){
            s1.pop();         
        }
        else s1.push(s[i]);
        i++;
    }
    while(!s1.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};