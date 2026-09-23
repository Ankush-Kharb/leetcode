class Solution {
public:
    int numberSub(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> hash(m + 1, 0);
        int l = 0;
        int r = 0;
        int count = 0;
        int number = 0;
        while (r < n) {
            if (hash[nums[r]] == 0) {
                count++;
            }
            hash[nums[r]]++ ;
            while(count > k){
                hash[nums[l]]--;
                if(hash[nums[l]] == 0){
                    count--;
                }
                l++;
            }
            r++;
            number += (r-l+1);
        }
        return number;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = numberSub(nums , k) - numberSub(nums , k-1);
        return ans ;
    }
};