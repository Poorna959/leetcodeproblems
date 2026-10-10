class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       int ans=0;
       int l=0;
       unordered_map<int,int> memo;
       for(int r=0;r<n;r++){
            memo[nums[r]]++;
            sum+=nums[r];
            while(memo[nums[r]]==2){
                sum-=nums[l];
                memo[nums[l]]--;
                l++;
            }

            ans = max(ans,sum);
       } 
       return ans;
    }
};