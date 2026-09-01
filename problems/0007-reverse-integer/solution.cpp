class Solution {
public:
    int reverse(int x) {
        int rev =0;
        int num =0;
       
        while(x!=0){
        rev = x%10;
        x/=10; 
        if (num > INT_MAX/10 || (rev == INT_MAX/10 && num > 7)) return 0;
        if (num < INT_MIN/10 || (rev == INT_MIN/10 && num < -8)) return 0;
        num = num*10 + rev;
        
        }return num;
        
    }
};