class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long num1 = num/3;
        long long num2 = num1+1;
        long long num3 = num1-1;
        if(num1 + num2 +num3 == num){
            return{num3,num1,num2};
        }else return{};
        
    }
};