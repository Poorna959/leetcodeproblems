class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> memo;
        memo[0]=1;
        int currsum=0;
        int totalsub=0;
        for(int n:nums){
            currsum+=n;
            if(memo.find(currsum-goal)!=memo.end()){
                totalsub+=memo[currsum-goal];

            }
            memo[currsum]++;
        }
        return totalsub;
    }
};