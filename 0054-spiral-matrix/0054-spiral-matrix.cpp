#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Handle empty matrix safely
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m - 1, scol = 0, ecol = n - 1;
        vector<int> ans;
        
        while (srow <= erow && scol <= ecol) {
            // 1. Top boundary: traverse from left to right
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]); 
            }

            // 2. Right boundary: traverse from top to bottom
            for (int j = srow + 1; j <= erow; j++) {
                ans.push_back(matrix[j][ecol]); 
            }

            // 3. Bottom boundary: traverse from right to left
            for (int i = ecol - 1; i >= scol; i--) {
                if (srow == erow) { // Safety check for single remaining row
                    break;
                }
                ans.push_back(matrix[erow][i]); 
            }

            // 4. Left boundary: traverse from bottom to top
            for (int j = erow - 1; j > srow; j--) { 
                if (scol == ecol) { // Safety check for single remaining column
                    break;
                }
                ans.push_back(matrix[j][scol]); 
            }

            // Shrink boundaries inwards
            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};
