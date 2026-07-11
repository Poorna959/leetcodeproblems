class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> ans = {-1, -1};
        if (nums.empty()) return ans;

        // 1. Find the first occurrence (Left Bound)
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid; // Squeeze right to find the earliest match
            } else {
                l = mid + 1;
            }
        }
        
        // If the target doesn't exist, return [-1, -1]
        if (nums[l] != target) return ans;
        ans[0] = l;

        // 2. Find the last occurrence (Right Bound)
        r = nums.size() - 1; // Keep 'l' where it is, reset 'r'
        while (l < r) {
            // Biased to the right to prevent infinite loops when l and r are adjacent
            int mid = l + (r - l + 1) / 2; 
            if (nums[mid] <= target) {
                l = mid; // Squeeze left to find the latest match
            } else {
                r = mid - 1;
            }
        }
        ans[1] = r;

        return ans;
    }
};