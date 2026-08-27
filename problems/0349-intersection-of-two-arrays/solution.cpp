class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums2 (or the larger one)
        sort(nums2.begin(), nums2.end());
        
        unordered_set<int> result;

        for (int num : nums1) {
            if (binarySearch(nums2, num)) {
                result.insert(num); // store unique values
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};