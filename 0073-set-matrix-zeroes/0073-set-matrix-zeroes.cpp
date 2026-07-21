class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row = false;
        bool first_col = false;
        
        // 1. Check if the first row has any zeros
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                first_row = true;
                break;
            }
        }
        
        // 2. Check if the first column has any zeros
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                first_col = true;
                break;
            }
        }
        
        // 3. Use the first row and column as markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // 4. Update inner cells using OR (||) and assignment (=)
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0; 
                }
            }
        }
        
        // 5. Handle the first row
        if(first_row){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        
        // 6. Handle the first column
        if(first_col){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
