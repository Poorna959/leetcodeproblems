class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            // Fix 3: Standardize the j-loop to cleanly skip duplicates at the start
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
               
                int l = j + 1, r = n - 1;
                while(l < r){
                    // Excellent job casting to long long to prevent integer overflow!
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    
                    if(sum < target){
                        l++;
                    }
                    else if(sum > target){ // Fix 1: Changed 'if' to 'else if'
                        r--;
                    }
                    else { // sum == target
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        
                        // Fix 2: Move updates INSIDE the successful match block
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(i>0 && nums[i]==nums[i-1])continue;
//             for(int j=i+1;j<n;){
               
//                 int l=j+1,r=n-1;
//                 while(l<r){
//                     long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r];
//                     if(sum<target){
//                         l++;
//                     }
//                     else if(sum>target){
//                         r--;
//                     }
//                     else{
//                         ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    
//                     l++;r--;
//                     while(l<r && nums[l]==nums[l-1])l++;
//                     while(l<r && nums[r]==nums[r+1])r--;
//                     }
//                 }
//                 j++;
//                 while(j<n && nums[j]==nums[j-1])j++;
//             }

//         }
//     return ans;
//     }
// };