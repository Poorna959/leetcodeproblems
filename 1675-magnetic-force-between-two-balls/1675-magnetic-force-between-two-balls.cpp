class Solution {
private:
    bool isvalid(vector<int>&nums , int diff,int k){
        int last_pos=0;
        int count=1;
        int n =nums.size();
        for(int i=1;i<n;i++){   
            if(nums[i]-nums[last_pos]>=diff){
                count++;
                last_pos = i;
            }
            if(count==k){
                return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int l=0,h=position[n-1]-position[0];
        int ans =0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isvalid(position,mid,m)){
                ans = mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};