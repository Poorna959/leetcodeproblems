class Solution {
private:
    int atmost(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int n = nums.size();
        int l =0;
        int sum =0;
        int count = 0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=r-l+1;        }
            return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};