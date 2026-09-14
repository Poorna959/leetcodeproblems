class Solution {
    static bool comp(vector<int> &a,vector<int> &b){
            return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end(),comp);
            int n = intervals.size();
            int lastend = INT_MIN;
            int count=0;
            for(int i =0;i<n;i++){
                if(intervals[i][0]>=lastend){
                    lastend = intervals[i][1];
                }
                else{
                    count++;
                }
            }
            return count;
    }
};