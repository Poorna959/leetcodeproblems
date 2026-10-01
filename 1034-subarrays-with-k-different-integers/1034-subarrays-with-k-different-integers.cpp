class Solution {
private:
    int atmost(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> memo;
        int count =0;
        int l=0;
        for(int r=0;r<n;r++){
            memo[nums[r]]++;
            while(memo.size()>k)
            {
                memo[nums[l]]--;
                if(memo[nums[l]]==0){
                    memo.erase(nums[l]);
                }
                l++;
            }
            count+=(r-l+1);
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmost(nums,k)-atmost(nums,k-1);
    }
};