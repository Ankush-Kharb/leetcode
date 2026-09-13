class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows = n;
        int cols = n;

        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        int count = 1;
        int total = rows * cols;

        while (count <= total) {
            for (int col = left; col <= right && count <= total; col++) {
                ans[top][col] = count++;
                
            }
            top++;

            for (int row = top; row <= bottom && count <= total; row++) {
                ans[row][right]= count++;
            }
            right--;

            for (int col = right; col >= left && count <= total; col--) {
                ans[bottom][col]= count++;
            }
            bottom--;

            for (int row = bottom; row >= top && count <= total; row--) {
                ans[row][left] = count++; 
            }
            left++;
        }

        return ans;

    }
};