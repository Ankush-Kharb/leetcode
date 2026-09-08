class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows;
        vector<int> col;
        for(int i = 0 ; i<m; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for (int i = 0 ; i< rows.size();i++){
            for(int j = 0; j<n;j++){
                matrix[rows[i]][j]=0;
                
            }       
        }
        for (int i = 0 ; i< col.size();i++){
            for(int j = 0; j<m;j++){
                matrix[j][col[i]]=0;
            }
        }
        
        
    }
};