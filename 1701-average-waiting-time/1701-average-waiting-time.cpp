class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double current_time=0;
        double total_time=0;
        for(auto &customer:customers){
            int arrival=customer[0];
            int time = customer[1];
            if(arrival>current_time){
                current_time=arrival;
            }
            current_time+=time;
            total_time+=current_time-arrival;

        }
        return (double)total_time/(customers.size());
    }
};