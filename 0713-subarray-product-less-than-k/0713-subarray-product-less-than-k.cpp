class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int count=0;
        int pro = 1;
        for(int r=0;r<n;r++){
            pro*=nums[r];
            while(l<=r && pro>=k){
                pro/=nums[l];
                l++;
            }
            count+=(r-l+1);
        }
        return count;
    }
};