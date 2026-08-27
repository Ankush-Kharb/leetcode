class Solution {
public:
    int sum(vector<int>&nums,int mid){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((double)nums[i]/mid);
        }
        return sum;
    }



    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid;
        int ans ;
        while(low<=high){
            mid = (low+high)/2;
            int total_sum = sum(nums,mid);
            if (total_sum <= threshold){
                ans = mid;
              high = mid - 1; 
            }
            else  low = mid+1;

        }return ans;
        
    }
};


