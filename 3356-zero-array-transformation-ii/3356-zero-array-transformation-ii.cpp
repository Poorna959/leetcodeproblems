class Solution {
public:
        bool check(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Apply only the first 'k' queries
        for (int i = 0; i < k; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];

            diff[start] += val;
            diff[end + 1] -= val;
        }

        int current_decrement = 0;
        for (int i = 0; i < n; i++) {
            current_decrement += diff[i];
            
            // If total maximum allowed decrements at index i cannot reduce nums[i] to 0
            if (current_decrement < nums[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0;
        int high = queries.size();
        int ans = -1;

        // Binary search for the minimum possible k
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, queries, mid)) {
                ans = mid;       // 'mid' queries work, record it as a candidate answer
                high = mid - 1;  // Try to find a smaller k
            } else {
                low = mid + 1;   // 'mid' queries are not enough, we need more queries
            }
        }

        return ans;
    }

};