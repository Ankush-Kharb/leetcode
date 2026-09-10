class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> ans;
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        int count = 0;
        int total = rows * cols;

        while (count < total) {
            for (int col = left; col <= right && count < total; col++) {
                ans.push_back(matrix[top][col]);
                count++;
            }
            top++;

            for (int row = top; row <= bottom && count < total; row++) {
                ans.push_back(matrix[row][right]);
                count++;
            }
            right--;

            for (int col = right; col >= left && count < total; col--) {
                ans.push_back(matrix[bottom][col]);
                count++;
            }
            bottom--;

            for (int row = bottom; row >= top && count < total; row--) {
                ans.push_back(matrix[row][left]);
                count++;
            }
            left++;
        }

        return ans;
    }
};
