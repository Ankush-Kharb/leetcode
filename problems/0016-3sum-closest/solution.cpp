class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j ;
        int k ;
        int ans;
        long long sum ;
        long long max_sum = INT_MIN;
        long long min_sum = INT_MAX;
        long long diff1;
        long long diff2;
        while(i<n){
            j = i+1;
            k = n-1;
            while(j<n && k>j){
                sum = nums[j]+nums[k]+nums[i];
                if (sum <= target){
                max_sum = max(sum , max_sum);
                j++;
                }
                else {
                min_sum = min(sum , min_sum);
                k--;
                }

            }
            i++;
        }
        // cout << max_sum <<" "<< min_sum;
        // diff1 = abs(target - max_sum);
        // diff2 = abs(target - min_sum);
        // ans = min(diff1 , diff2);

        int x = max_sum;
        int y = min_sum;

        
        if(x>y)
        {
            int cnt1 = 0;
            int cnt2 = 0;
            while(x!=target)
            {
                x--;
                cnt1++;
            }

            while(y!=target)
            {
                y++;
                cnt2++;
            }

            if(cnt2<cnt1) return y;
            return x;
        }
        else
        {
            diff1 = target - max_sum;
            diff2 = min_sum - target;
            if(diff1 > diff2){
                return diff2 + target;
            }
            else return target - diff1;
        }



       
        
    }
};