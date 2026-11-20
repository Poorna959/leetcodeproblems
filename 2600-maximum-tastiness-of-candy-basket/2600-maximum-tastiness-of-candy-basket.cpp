class Solution {
bool isvalid(vector<int>& price ,int diff,int k){
    int last_pos = 0;
    int count = 1;
    int n = price.size();
    for(int i=1;i<n;i++){
        if(price[i]-price[last_pos]>=diff){
            count++;
            last_pos=i;
        }
        if(k==count){
            return true;
        }
    }   
    return false;
}
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n= price.size();
        int ans =0;
        sort(price.begin(),price.end());
        int l = 0,h=price[n-1]-price[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isvalid(price,mid,k)){
                ans = mid;
                l =mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};