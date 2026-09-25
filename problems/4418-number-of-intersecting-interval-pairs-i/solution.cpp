class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        for(int i = 0 ; i<intervals.size()-1; i++){
            int u = intervals[i][0];
            int v = intervals[i][1];
            for(int j = i+1 ; j < intervals.size() ; j++){
                int a = intervals[j][0];

                int b = intervals[j][1];

                if (a <= v && b >= u) {

                    count++;

                }
            }
            
        }return count;
    }
};