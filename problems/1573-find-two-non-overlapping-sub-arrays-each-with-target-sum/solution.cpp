class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0;
        int right = 0;
        int n = arr.size();
        int subSum = 0;

        vector<int> dp(n, INT_MAX);

        int best = INT_MAX;
        int ans = INT_MAX;

        while (right < n) {
            subSum += arr[right];
            while (left <= right && subSum > target) {
                subSum -= arr[left];
                left++;
            }
            if (right > 0) {
                dp[right] = dp[right - 1];
            }
            if (subSum == target) {
                int curr = right - left + 1;
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, dp[left - 1] + curr);
                }
                dp[right] = min(dp[right], curr);
            }
            right++;
        }
        
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};