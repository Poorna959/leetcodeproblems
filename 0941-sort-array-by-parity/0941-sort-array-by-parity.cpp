class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int l  =-1;
        int r= 0;
        while(r<n){
            if(nums[r]%2==0){
                l++;
                swap(nums[l],nums[r]);
            }
            r++;
        }
        return nums;
    }
};