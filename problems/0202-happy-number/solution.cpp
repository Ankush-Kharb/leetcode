class Solution {
public:
    bool isHappy(int n) {
        while(n>4){
            int temp = n;
            n = 0;
        while(temp!=0 ){ 
            int x = temp%10;
            temp = temp/10;
            n += x*x;
            
        }
      
        } 
        if(n==1)return true;
        else return false  ;
        
        }
        
};