class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        ans[0]=-1;
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=(total+nums[i])%k;
            if(ans.find(total)!=ans.end()){
                if(i-ans[total]>=2){
                    return true;
                }
            }
            else ans[total]=i;
        }
        return false;
    }
};