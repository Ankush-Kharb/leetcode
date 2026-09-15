class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int>ans;
        ans.reserve(rows * cols);
        int change = 0;
        while(change <= rows+cols-2){
            if(change%2 == 0){
                int i= min(change , rows-1);
                int j = change - i;
                while(i>=0 && j<cols){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }

            }
            else{
                int j = min(change , cols -1);
                int i = change - j;
                while(j>=0 && i<rows){
                    ans.push_back(mat[i][j]);
                        j--;
                        i++;
                    }
                } change++;
            }
            return ans;
           
        

        
    }
};