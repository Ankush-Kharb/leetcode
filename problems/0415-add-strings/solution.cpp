class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int i = n1 -1;
        int j = n2 -1;
        string ans;
        int sum;
        int carry = 0;
        while(i>=0  ||  j>=0 || carry ){
        int x = i>=0 ? num1[i]-'0':0;
        int y = j>=0 ? num2[j]-'0':0;
        sum = x + y + carry ;
        ans.push_back(sum%10 + '0');
        carry = sum / 10;
        i-- ; j--;
       
        }reverse(ans.begin(),ans.end());
        return  ans;
        
    }
};