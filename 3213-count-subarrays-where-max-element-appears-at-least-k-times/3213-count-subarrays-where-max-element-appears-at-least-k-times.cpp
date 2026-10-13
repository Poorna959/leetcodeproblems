class Solution {
long long atmost(vector<int>& nums, int target,int freq){
    int n = nums.size();
    int  l =0;
    long long count = 0;
    int temp = 0;
    for(int r=0;r<n;r++){
        if(nums[r]==target){
            temp++;
        }
        while(temp>freq){
            if(nums[l]==target){
                temp--;
            }
            l++;
        }
        count+=(r-l+1);
    }
    return count;
}
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long t = (n * (n + 1)) / 2;
        long long max_ele = *max_element(nums.begin(),nums.end());
        return t-atmost(nums,max_ele,k-1);
    }
};