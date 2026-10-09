class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int ans = 0;
        unordered_map<int,int>  memo;
        int temp = 0;
        for(int  r= 0;r<n;r++){
            memo[nums[r]]++;
            temp += nums[r];
            while(memo[nums[r]]==2){
                temp-=nums[l];
                memo[nums[l]]--;
                l++;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};