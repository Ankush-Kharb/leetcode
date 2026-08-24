class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR = nums[0];
        for (int i=1 ;i<n;i++)
        {
            XOR ^= nums[i];
            }
        return XOR;
    }
};