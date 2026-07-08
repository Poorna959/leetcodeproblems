class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int left=0,n=nums.size();
       if(n==1 && nums[0]==target){
        return 1;
       }
       int min_len=INT_MAX;
       long int sum=0;
       for(int right=0;right<n;right++){
        sum+=nums[right];
        while(sum>=target){
            min_len=min(min_len,right-left+1);
            sum=sum-nums[left];
            left++;
        }
       }
       if(min_len==INT_MAX){
        return 0;
       }
       else return min_len;

    }
};