class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ans;
        
        // Base case: A prefix sum of 0 conceptually occurs before the array starts (index -1)
        ans[0] = -1;
        
        int n = nums.size();
        int max_len = 0;
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (nums[i] == 0) {
                total -= 1;
            } else {
                total += 1;
            }
            
            
            if (ans.find(total) != ans.end()) {
                max_len = max(max_len, i - ans[total]);
            } else {
                // ONLY store the first time we see a sum to maximize subarray length
                ans[total] = i;
            }
        }
        return max_len;
        
    }
};