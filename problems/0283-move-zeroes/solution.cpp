class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>nums2;
        for (int i=0;i<n;i++){
            if(nums[i]!=0)
            nums2.push_back(nums[i]);
        }
       
        for(int i=nums2.size();i<n;i++)
        { 
            nums2.push_back(0);
            }
         nums.swap(nums2);
    }
};