class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n= nums.size();
        int l=0;
        long long count = 0;
        map<int,int>memo;
        for(int r=0;r<n;r++){
            memo[nums[r]]++;
            while(abs(memo.rbegin()->first-memo.begin()->first)>2){
                memo[nums[l]]--;
                if(memo[nums[l]]==0){
                    memo.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }
};