class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int ans = 0;
        int count= 0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                count++;
            }
            while(count>1){
                if(nums[l]==0){
                    count--;
                }
                l++;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};