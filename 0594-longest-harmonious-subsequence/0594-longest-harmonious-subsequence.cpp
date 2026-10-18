class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int l=0;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[l]>1){
                l++;
            }
            if(nums[r]-nums[l]==1 && r<n){
                ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};