class MyCalendarThree {
private:
    map<int,int> chart;
public:
    MyCalendarThree() {        
    }
    
    int book(int startTime, int endTime) {
        chart[startTime]+=1;
        chart[endTime]-=1;
        int change=0;
        int k=0;
        for(auto &[time,i]:chart){
            change+=i;
            k=max(k,change);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */