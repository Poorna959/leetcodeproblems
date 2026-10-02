class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int> memo;
        int l=0;
        long long count =0;
        for(int r=0;r<n;r++){
            memo[nums[r]]++;
            while(abs(memo.rbegin()->first-memo.begin()->first)>2){
                memo[nums[l]]--;
                if(memo[nums[l]]==0){
                    memo.erase(nums[l]);
                }
                l++;
            }
            if(abs(memo.rbegin()->first-memo.begin()->first)<=2){
                count+=r-l+1;
            }

        }
        return count;
    }
};