class Solution {
private:
    // Changed 'diff' to long long
    bool isvalid(vector<int>& nums, long long diff, int k) {
        long long sum = 0;
        for (int b : nums) {
            // Cast 'b' to long long to match 'diff' in std::min
            sum += min((long long)b, diff);
        }
        return sum >= (long long)k * diff;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans = 0;
        long long l = 1;
        // Used 0LL to prevent 32-bit integer overflow during summation
        // Divided by n as a tighter, valid upper bound
        long long h = accumulate(batteries.begin(), batteries.end(), 0LL) / n; 
        
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (isvalid(batteries, mid, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
