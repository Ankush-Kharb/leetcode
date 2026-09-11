class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int l1 = 0; 
        int l2 = (n/2);
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0 ; i< l2 ; i++){
            sum1 += nums[i];
        }
        for(int i = l2 ; i<n ;i++){
            sum2 += nums[i];
        }
        int count = 0;
        while(l2 < n){
            if(sum1 != sum2)count++;
            sum1 = sum1 - nums[l1] + nums[l2];
            sum2 = sum2 - nums[l2] + nums[l1];
            l1++;
            l2++;
        }
        return count;
    }
};