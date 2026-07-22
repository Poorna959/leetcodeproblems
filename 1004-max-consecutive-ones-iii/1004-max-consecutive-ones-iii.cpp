class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_ans=0;
        int zeros=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zeros+=1;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            max_ans=max(max_ans,r-l+1);
        }
        return max_ans;

    }
};