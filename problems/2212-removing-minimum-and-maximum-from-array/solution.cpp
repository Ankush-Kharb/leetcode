class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minI = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxI = max_element(nums.begin(), nums.end()) - nums.begin();
        if (minI > maxI)
            swap(minI, maxI);

        int front = maxI + 1;

        int back = n - minI;

        int bothSides = (minI + 1) + (n - maxI);

        return min({front, back, bothSides});
    }
};