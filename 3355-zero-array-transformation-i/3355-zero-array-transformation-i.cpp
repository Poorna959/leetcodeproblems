class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(auto &queri:queries){
            int start=queri[0];
            int end=queri[1];

            diff[start]+=1;
            diff[end+1]-=1;
        }
        int change=0;
        for(int i=0;i<n;i++){
            change+=diff[i];
            if(change<nums[i]){
                return false;
            }
        }
        return true;
    }
};