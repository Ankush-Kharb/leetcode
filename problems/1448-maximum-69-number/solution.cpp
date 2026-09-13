class Solution {
public:
    int maximum69Number (int num) {
        string s =to_string(num);
        int n = s.size();
        int i =0;
        while(i<n){
            if(s[i]=='9'){
                i++;
            }
            else if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int ans= stoi(s);
        return ans;
        
    }
};