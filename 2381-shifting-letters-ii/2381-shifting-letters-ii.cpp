class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        // Difference array initialized to 0
        vector<int> diff(n + 1, 0);
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int val = (shift[2] == 1) ? 1 : -1;
            
            diff[start] += val;
            diff[end + 1] -= val;
        }
        
        int current_shift = 0;
        
        // Step 2: Apply cumulative prefix sums to modify the string
        for (int i = 0; i < n; i++) {
            current_shift += diff[i];
            
            // Normalize shift to be within [0, 25] handles negative values properly
            int net_shift = (current_shift % 26 + 26) % 26;
            
            // Shift the character safely
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        
        return s;
    }
};