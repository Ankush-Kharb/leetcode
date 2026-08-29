class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string final_ans = "0";
        int i = n-1;
       while(i>=0){
            if((num[i]-'0')%2 == 1){
                return num.substr(0,i+1);
        }
        else i--;
        }return "";
        
    }
};