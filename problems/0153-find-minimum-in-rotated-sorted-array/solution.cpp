class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid;
        int high = n-1;
        int ans = 5000;
        while(low<=high){
            mid = low + ((high - low)/2);
            

            //LEFT SIDE SORTED
            if (nums[low]<=nums[mid]){
                ans = min (ans , nums[low]);
                low = mid+1;
             
            }

            //RIGHT SIDE SORTED
            else {
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }return ans;
        
    }
};