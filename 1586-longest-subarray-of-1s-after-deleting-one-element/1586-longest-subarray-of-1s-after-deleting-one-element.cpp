class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int  l =0,r=0;
        int max_count  = INT_MIN;
        int zero_count = 0 ;
        
        for(r=0;r<n;r++){
            if(nums[r]==0){
                zero_count++;
            }
            while(zero_count>1){
                if(nums[l]==0){
                    zero_count--;
                }
                l++;
            }
            max_count = max(max_count,r-l);
            
        }
        return max_count;
    }
};