class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>memo;
        for(int r=0;r<n;r++){
            if(memo.find(nums[r])!=memo.end()){
                if(abs(memo[nums[r]]-r)<=k){
                    return true;
                }
                memo[nums[r]]=r;
            }
            else{
                memo[nums[r]]=r;
            }
    
        }
        return false;
    }
};