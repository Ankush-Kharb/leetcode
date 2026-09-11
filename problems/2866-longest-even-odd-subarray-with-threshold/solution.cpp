class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int l = 0;
        int n = nums.size();
        int r = 0;
        int ans = 0;
        while(r < n){
            if(nums[r]%2 == 0 && nums[r]<= threshold){
                l = r;
                int rParity = 1;
                while(r < n){
                   if(nums[r]%2 != rParity && nums[r]<= threshold){
                    rParity = 1-rParity;
                    r++;
                   } 
                   else{
                    break;
                   }
                }
                ans = max(ans , r-l);
                l = r;
            }
            else {
                r++;
            }
        }
        return ans;
    }
};