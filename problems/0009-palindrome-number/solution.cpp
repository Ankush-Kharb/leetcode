class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string str = to_string(x);
        int n = str.length();
        int low= 0;
        int high = n-1;
        while(low<=high){
            if(str[low]==str[high]){
                low++;
                high--;
            }else return false;
        }return true;
        
    }
};
