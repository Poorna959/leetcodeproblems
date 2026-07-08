class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int max_len=0;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[l]>1 ){
                l++;
            }
            if(nums[r]-nums[l]==1 && r<n){            
            max_len=max(max_len,r-l+1);
        }
        }
        return max_len;
    }
};