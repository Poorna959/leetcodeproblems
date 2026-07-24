class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double cheftime=0;
        double wait_time=0;
        for(auto i:customers){
            if(cheftime>i[0]){
                cheftime+=i[1];
            }
            else{
                cheftime=i[0]+i[1];
            }
            wait_time+=cheftime-i[0];
        }
        double ans=wait_time/(customers.size());
        return ans;
    }
};