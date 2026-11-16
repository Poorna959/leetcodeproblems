class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        int total = 0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            prefix[i] = total;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            int start = max(0,i-nums[i]);
            if(start==0){
                sum+=prefix[i];
            }
            else{
                sum+=prefix[i]-prefix[start-1];
            }
        }
        return sum;
    }
};