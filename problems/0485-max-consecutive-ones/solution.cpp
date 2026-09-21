class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int l = 0;
        int maxi = 0;
        int maxN;
        int sum = 0;
        while(r<n){
            if(nums[r]==1){
                maxi++;
                maxN = max(maxi,maxN);
                r++;
            }
            else{
                l= r+1;
                r++;
                maxi = 0;
            }
        }
        return maxN;
    }
};