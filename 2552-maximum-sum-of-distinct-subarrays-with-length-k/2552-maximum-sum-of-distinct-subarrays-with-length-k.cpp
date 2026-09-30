class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0;
        int l =0; 
        long long  sum = 0;
        unordered_set<int>set;
        for(int r=0;r<n;r++){
            while(set.count(nums[r])){
                set.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            set.insert(nums[r]);
            sum+=nums[r];
            if(r-l+1==k){
            max_sum= max(max_sum,sum);
            set.erase(nums[l]);
            sum-=nums[l];
            l++;
            }
        }
        return max_sum;
    }
};