class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> count;
        int max_destroyed=0;
        int ans=INT_MAX;
        for(auto num:nums){
            max_destroyed=max(max_destroyed,++count[num%space]);
        }
        for(auto num:nums){
            if(count[num%space]==max_destroyed){
                ans=min(ans,num);
            }
        }
        return ans;
        // unordered_map<int, int> remainder_counts;
        // unordered_map<int, int> min_val_for_remainder;
        
        // int max_destroyed = 0;
        // int ans = INT_MAX;
        
        // // Step 1: Populate counts and track the minimum element for each remainder
        // for (int num : nums) {
        //     int rem = num % space;
        //     remainder_counts[rem]++;
            
        //     if (min_val_for_remainder.find(rem) == min_val_for_remainder.end()) {
        //         min_val_for_remainder[rem] = num;
        //     } else {
        //         min_val_for_remainder[rem] = min(min_val_for_remainder[rem], num);
        //     }
            
        //     max_destroyed = max(max_destroyed, remainder_counts[rem]);
        // }
        
        // // Step 2: Find the minimum seed that yields the maximum target destruction
        // for (int num : nums) {
        //     int rem = num % space;
        //     if (remainder_counts[rem] == max_destroyed) {
        //         ans = min(ans, min_val_for_remainder[rem]);
        //     }
        // }
        
        // return ans;
    }
};
