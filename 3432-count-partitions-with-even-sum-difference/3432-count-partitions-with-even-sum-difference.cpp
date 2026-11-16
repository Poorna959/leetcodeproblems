class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int total = 0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            prefix[i]=total;
        }
        total = 0;
        for(int i=n-1;i>=0;i--){
            
            suffix[i] =total;
            total+=nums[i];
        }
        int count = 0;
        for(int i = 0;i<n-1;i++){
            if(abs(prefix[i]-suffix[i])%2==0){
                count++;
            }
        }
        return count;
    }
};