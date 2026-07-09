class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int total=0;
        for(auto i :nums){
            total+=i;
            ans.push_back(total);
        }
        return ans;
        
    }
};