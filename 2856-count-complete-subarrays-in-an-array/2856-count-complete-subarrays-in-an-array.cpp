class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        unordered_set<int> dis;
        for(int i=0;i<n;i++){
            dis.insert(nums[i]);
        }
        int total_dist = dis.size();
        int l=0;
        unordered_map<int,int> memo;
        for(int r=0;r<n;r++){
            memo[nums[r]]++;
            while(memo.size()==total_dist){
                memo[nums[l]]--;
                count+=n-r;
                if(memo[nums[l]]==0){
                    memo.erase(nums[l]);
                }
                l++;
                
            }
        }
        return count;
    }
};