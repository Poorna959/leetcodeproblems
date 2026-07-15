class Solution {
public:
    
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return calculate(nums,0,memo);
    }
    int calculate(vector<int>& nums,int ind,vector<int> &memo){
        if(ind>=nums.size()-1){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        
        
        int mini=1e9;
        for(int i=1;i<=nums[ind];i++){
            mini=min(mini,1+calculate(nums,ind+i,memo));
        }
        memo[ind]=mini;
        return mini;
    }
};