class Solution {
public:
    int numberG(vector<int>& nums, int goal) {
        int n = nums.size();
        int r = 0;
        int l = 0;
        int sum = 0;
        int count = 0;
        if(goal < 0){
            return 0;
        }
        while (r < n) {
            sum = sum + nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans; 
        ans = numberG(nums , goal) - numberG(nums , goal-1);
        return ans;

    }
};