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
                count+=ans[total-k];}
            ans[total]++;
        }
        return count;


        // int  count=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};