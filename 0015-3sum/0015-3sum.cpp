class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
          sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Fix the first element 'i'
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element to avoid identical triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int l = i + 1;
            int r = n - 1;
            int target = -nums[i]; // We want nums[l] + nums[r] == -nums[i]
            
            while (l < r) {
                int sum = nums[l] + nums[r];
                
                if (sum == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    // Skip duplicates for the second element
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    // Skip duplicates for the third element
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    
                    // Move both pointers inward to look for other pairs
                    l++;
                    r--;
                } 
                else if (sum > target) {
                    r--; // Sum is too large, make it smaller
                } 
                else {
                    l++; // Sum is too small, make it larger
                }
            }
        }
        
        return ans;
    }
};