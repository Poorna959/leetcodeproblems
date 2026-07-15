class Solution {
public:
    
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int jumps=0;
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(nums[i]+i,farthest);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
    
};
// this is baed on the range ;
// where you use the a point to check in which range you can jummp and if the r exceeds the limit the jumps will be minimum;
