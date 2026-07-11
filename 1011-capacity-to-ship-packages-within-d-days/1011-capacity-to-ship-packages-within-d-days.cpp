class Solution {
public:
    bool isValid(vector<int>& weights,int capacity, int days){
        int current_days = 1; // Start on day 1
        int current_weight = 0;
        
        for (int weight : weights) {
            if (current_weight + weight > capacity) {
                current_days++;      // Move to the next day
                current_weight = 0;  // Reset ship load for the new day
            }
            current_weight += weight;
            
            if (current_days > days) return false; // Early exit if we exceed allowed days
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=0;
        for(int i:weights){r+=i;}
        int l=*max_element(weights.begin(),weights.end());
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(weights,mid,days)){
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