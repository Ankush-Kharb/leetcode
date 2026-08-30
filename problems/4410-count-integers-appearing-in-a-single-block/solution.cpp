class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        vector<int> vis(101,0);
        int n = nums.size();
        vector<int> freq(101, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
       
        for (int i = 0; i < n;) {
            int x = nums[i];
            while (i < n && nums[i] == x) {
                freq[x]--;
                i++;
            }
            if (freq[x] == 0 && vis[x] == 0) {
                count++;
            }
            vis[x] = 1;
        }
        return count;
    }
};