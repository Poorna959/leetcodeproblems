class Solution {
public:
    bool isValid(vector<int>& piles, int rate,int hour){
        long long  total_hours = 0; // Use long long to prevent integer overflow
        for (int pile : piles) {
            total_hours += (pile + rate - 1) / rate;
            if (total_hours > hour) return false; 
        }
        return total_hours <= hour;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(piles,mid,h)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};