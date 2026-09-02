class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        int add;
        while(num != 0){
            add = num%10;
            sum+=add;
           num = num/10;
            if(num == 0 && sum>9){
            num = sum;
            sum=0;
            }

        }
         return sum;
        
    }
};