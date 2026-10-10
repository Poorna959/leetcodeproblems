class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int  l =0;
        unordered_map<int,int> memo;
        for(int r=0;r<n;r++){
            memo[nums[r]]++;
            while(memo[nums[r]]>k){
                memo[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
        }
    };