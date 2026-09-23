class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        int maxReach = 0;
        if(n == 1){
            return true;
        }
        while(i<n){
            if(i > maxReach){
               return false;
            }
            maxReach = max(maxReach ,i+nums[i]);
            i++;
        }
        return true ;

    }
};