class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_ans =INT_MAX;
        int l=0;
        int sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                min_ans= min(min_ans,r-l+1);
                sum-=nums[l];
                l++;
               
            }
            
        }
        return (min_ans==INT_MAX)?0:min_ans;
    }
};