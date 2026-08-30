class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        int low = 0;
        int high = n-1;
        while(low<high){
            if(nums[low]+nums[high]== target)return{low+1,high+1};
            else if(nums[low]+nums[high]>target)high--;
            else low++;
            
        }return{-1,-1};
        
    }
};