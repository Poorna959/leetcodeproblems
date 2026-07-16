class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int,vector<vector<int>>> memo;
        return calculate(candidates,target,memo);
        
    }
    vector<vector<int>> calculate(vector<int>& num, int target, unordered_map<int, vector<vector<int>>>& memo) {
        // 1. Check memoization table
        if (memo.find(target) != memo.end()) {
            return memo[target];
        }
        
        // 2. Base cases
        if (target == 0) {
            return {{}}; // Returns a 2D vector containing one empty path
        }
        if (target < 0) {
            return {};   // Returns a completely empty 2D vector (invalid path)
        }

        vector<vector<int>> allWays;

        // 3. Explore options
        for (int i : num) {
            int remainder = target - i;
            auto subAnswers = calculate(num, remainder, memo);

            // If the remainder returned valid paths
            for (auto path : subAnswers) {
                // To avoid duplicate combinations like [2,3] and,
                // only build paths where elements stay sorted.
                if (path.empty() || i >= path.back()) {
                    path.push_back(i);
                    allWays.push_back(path);
                }
            }
        }

        // 4. Cache and return
        memo[target] = allWays;
        return allWays;
    }
};