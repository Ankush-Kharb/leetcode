class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        for (int i = 0; i < n; i++) {

            int shiftV = rowShift[i] % n;

            vector<int> temp(n);

            for (int j = 0; j < n; j++) {

                temp[j] = grid[i][(j + shiftV) % n];
            }

            grid[i] = temp;
        }
        for (int col = 0; col < n; col++) {
            int shiftV = colShift[col] % n;
            for (int k = 0; k < shiftV; k++) {
                int temp = grid[0][col];
                for (int j = 0; j < n - 1; j++) {
                    grid[j][col] = grid[j + 1][col];
                }
                grid[n - 1][col] = temp;
            }
        }
        return grid;
    }
};