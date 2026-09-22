class Solution {
public:
int numberOf(vector<int>& nums ,int k){
    int n = nums.size();
    int r =0;
    int l =0;
    int count = 0;
    int number = 0;
    while(r<n){
        if(nums[r]%2 != 0){
            count++;
        }
        while(count > k){
            if(nums[l]%2 != 0){
                count--;
                l++;
            }
            else l++;
        }
        number += (r-l+1);
        r++;
    }
    return number;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = numberOf(nums , k) - numberOf(nums , k-1);
        return ans;
    }
};