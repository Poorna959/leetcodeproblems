class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // The target sum for our middle subarray
        int target = total_sum - x;
        
        // If target is negative, it's impossible to reduce x to 0
        if (target < 0) return -1;
        // If target is 0, we must remove all elements
        if (target == 0) return n;
        
        int max_len = -1;
        int current_sum = 0;
        int l = 0;
        
        // Sliding window to find the longest subarray summing to target
        for (int r = 0; r < n; r++) {
            current_sum += nums[r];
            
            // Shrink the window from the left if the sum exceeds the target
            while (current_sum > target && l <= r) {
                current_sum -= nums[l];
                l++;
            }
            
            // If we found a valid subarray, track its maximum length
            if (current_sum == target) {
                max_len = max(max_len, r - l + 1);
            }
        }
        
        // If max_len was updated, the operations needed are total elements minus max_len
        return (max_len == -1) ? -1 : n - max_len;
    }
};