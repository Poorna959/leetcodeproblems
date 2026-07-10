class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto query:bookings){
            ans[query[0]-1]+=query[2];
            if(query[1]<n){
                ans[query[1]]-=query[2];
            } 
        }
        int freq=0;
        for(int i=0;i<n;i++){
            freq+=ans[i];
            ans[i]=freq;
        }
        return ans;

    }
};