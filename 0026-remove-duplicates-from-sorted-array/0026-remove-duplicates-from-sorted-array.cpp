class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0,right=0,n=nums.size();
        while(right<n){
            if(nums[left]==nums[right]){
                right++;
                continue;
            }
            else{
                swap(nums[left+1],nums[right]);
                left+=1;
                right+=1;
            }
        }
        return left+1;
    }
};