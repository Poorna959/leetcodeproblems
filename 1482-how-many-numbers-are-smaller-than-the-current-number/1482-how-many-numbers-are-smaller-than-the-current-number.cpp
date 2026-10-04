class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n=nums.size();
        map<int,int> memo;
        for(int i:nums)memo[i]++;
        int running=0;
        for(auto& [k,c]:memo){
            int cnt = c;
            c=running;
            running+=cnt;
        }

        vector<int> ans;
        for(int i:nums){
            ans.push_back(memo[i]);
        }
        return ans;
    }

};