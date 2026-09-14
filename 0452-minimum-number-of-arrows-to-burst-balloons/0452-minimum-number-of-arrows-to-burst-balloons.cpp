class Solution {
private:
    
    static bool comp(const vector<int> &a, const vector<int> &b) {         
    return a[1] < b[1];     
} 
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n = points.size();
        int arrows =1;

        int arrow = points[0][1];
        for(int i=1;i<n;i++){
            
            if(points[i][0]>arrow){
                arrows++;
                arrow  = points[i][1];
            }
            
        }
        return arrows;
    }
};