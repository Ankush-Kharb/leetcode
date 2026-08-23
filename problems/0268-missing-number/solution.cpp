class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1=0;
        int XOR2 = 0 ;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            XOR1 = XOR1^(i+1);
            XOR2 = XOR2^nums[i];
        }
        return XOR1^XOR2;
        
    }
};