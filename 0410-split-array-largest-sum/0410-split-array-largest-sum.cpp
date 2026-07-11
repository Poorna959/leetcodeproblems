class Solution {
public:
    bool isValid(vector<int>& nums, int capacity,int subs){
        int sum=0;
        int num=1;
        for(auto i:nums){
            if(sum+i>capacity){
                sum=0;
                num++;
            }
            if(num>subs){
                return false;
            }
            sum+=i;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=0;
        for(int i:nums)r+=i;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};