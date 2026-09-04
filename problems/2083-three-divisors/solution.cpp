class Solution {
public:
    bool isThree(int n) {
        int i = 1;
        int count = 0;
        for (int i = 1;i<=n;i++){
            if(n%i == 0)count++;
        }
        if(count == 3)return true;
        else return false;
        
    }
};