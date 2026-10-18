class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int l=0;
        long long sum = 0;
        unordered_set<int>memo;
        for(int r=0;r<n;r++){
            
            while(memo.count(nums[r])){
                sum-=nums[l];
                memo.erase(nums[l]);
                l++;
            }
            memo.insert(nums[r]);
            sum+=nums[r];
            if((r-l+1)==k){
                ans = max(ans,sum);
                memo.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};