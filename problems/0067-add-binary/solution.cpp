class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = n-1;
        int j = m-1;
        int carry = 0;
        string ans;
        while(i>=0 || j>= 0 || carry){
        int x = i>=0 ? a[i]-'0':0;
        int y = j>=0 ? b[j]-'0':0;
        int total  = x+y+carry;
        ans.push_back((total%2)+'0');
        carry = total/2;
        i--;j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};