class Solution {
public:
   int sub_arrays_formed(vector<int> &nums , int mid ){
    int n = nums.size();
    int sub_array = 1;
    long long sum = 0;
    for(int i = 0;i<n;i++){
        if ((sum + nums[i])<=mid){
            sum+=nums[i];
        }else {
            sub_array +=1;
             sum = nums[i];
            
        }
    }return sub_array;

   }



    int splitArray(vector<int>& nums, int k) {
        int n  = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int mid;
        while(low<=high){
            mid = (low+(high-low)/2);
            int number_of_subarrays = sub_arrays_formed(nums , mid);
            if (number_of_subarrays > k){
                low = mid+1;
                }
            else high = mid - 1;
        }return low;

    }
};