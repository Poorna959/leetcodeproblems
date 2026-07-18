class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int a = 0, b = 0, sum = 0;
        unordered_set<int> memo;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum += grid[i][j];
                if(memo.find(grid[i][j]) != memo.end()) {
                    a = grid[i][j];
                }
                memo.insert(grid[i][j]);
            }
        }
        
        
        int total_elements = n * n;
        int ideal = (total_elements * (total_elements + 1)) / 2;
        
       
        b = ideal - sum + a; 
        
        return {a, b};
    }
};
