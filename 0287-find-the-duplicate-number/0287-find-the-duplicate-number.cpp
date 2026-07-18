class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> memo;
        for(int i=0;i<n;i++){
            if(memo.find(nums[i])!=memo.end()){
                return nums[i];
            }
            memo.insert(nums[i]);
        }
    return -1;
    }
};