class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> memo;
        for(int i=0;i<nums.size();i++){
            int remainder=target-nums[i];
            if(memo.find(remainder)!=memo.end()){
                return {memo[remainder],i};
            }
            memo[nums[i]]=i;
        }
        return {};
    }
    
};