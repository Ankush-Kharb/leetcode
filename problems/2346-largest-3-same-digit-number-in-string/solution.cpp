class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        string compare;
        for(int i = 0; i< num.length()-2;i++){
            if(num[i]==num[i+1]&& num[i]==num[i+2]){
                compare = num.substr(i,3);
                if(compare>ans){
                    ans = compare;
                }
            }
        }
        return ans;
    }
};