class Solution {
private:
    int atmost(vector<int> & nums,int k){
        int n = nums.size();
        int temp =0;
        int l =0;
        int count = 0;
        for(int r=0;r<n;r++){
            if(nums[r]%2!=0){
                temp++;
            }
            while(temp>k){
                if(nums[l]%2!=0){
                    temp--;
                }
                l++;
            }
            count+=(r-l+1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};