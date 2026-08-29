class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows*cols;
        int low = 0;
        int high = n-1; //Treating matrix as 1D array
        int mid;
        while(low<=high){
            mid = low + (high - low)/2;
            int mid_value = matrix[mid / cols][mid % cols]; // Convert the 1D index back to 2D indices
            if(mid_value == target )return true;
            else if(mid_value > target) high = mid -1;
            else low = mid + 1;
        }return false;

    }
};