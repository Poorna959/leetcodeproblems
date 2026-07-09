class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> a;
        int n=nums.size();
        int left=0;
        int curr_sum=0;
        int max_sum=0;
        for(int right=0;right<n;right++){
            while(a.find(nums[right])!=a.end()){
                a.erase(nums[left]);
                curr_sum-=nums[left];
                left++;
            }
            a.insert(nums[right]);
            curr_sum+=nums[right];
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
};