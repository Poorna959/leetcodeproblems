class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l=0;
        int p = 1;
        for(int r = 0 ;r<n;r++){
            p= p*nums[r];
            while(l<r && p>=k){
                p/=nums[l];
                l++;
            }
            if(p<k){
                count+=r-l+1;
            }
        }
        return count;
    }
};