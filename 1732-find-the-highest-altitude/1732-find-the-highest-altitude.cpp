class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int total=0;
        int max_height=0;
        for(int i=0;i<gain.size();i++){
            total+=gain[i];
            max_height=max(max_height,total);
        }
        return max_height;
    }
};