class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        ans[0]=1;
        int count=0;
        int total=0;
        for(auto i:nums){
            total+=i;
            
            if(ans.find(total-k)!=ans.end()){
                count+=ans[total-k];
            }
            ans[total]++;
        }
        return count;
    }
};