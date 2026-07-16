class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m,vector<int>(n, -1));
        return calculate(m-1,n-1,table);
    }
    int calculate(int m,int n,vector<vector<int>> &memo){
         // 1. Out of bounds check: if we step off the grid, there are 0 paths
        if (m < 0 || n < 0) return 0;
        
        // 2. Base case: we successfully reached the starting top-left cell (0, 0)
        if (m == 0 && n == 0) return 1;
        
        // 3. Return cached result if already calculated
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        
        // 4. Move Up (m-1) and Move Left (n-1) to find paths coming into this cell
        memo[m][n] = calculate(m - 1, n, memo) + calculate(m, n - 1, memo);
        
        return memo[m][n];        
    }
};