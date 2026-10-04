class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
        vector<int> a = nums;
        sort(a.begin(),a.end());
        for(int j=0;j<n;j++){
            if(a[j]==nums[i]){
                ans.push_back(j);
                break;
            }   
        }}
        return ans;
    }
};