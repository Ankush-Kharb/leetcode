class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int s = 0;
        int e = 1;
        int l = 0;
        int r = 0;
        int p = 0;
        vector<vector<int>> ans;

        while (l < n) {
            p = l;
            r = l + 1;

            while (r < n && intervals[p][e] >= intervals[r][s]) {
                intervals[p][e] = max(intervals[p][e], intervals[r][e]);
                r++;
            }

            ans.push_back({intervals[l][s], intervals[p][e]});
            l = r;
        }
        return ans;
    }
};