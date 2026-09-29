class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int  l =0,r=n-1,lmax=INT_MIN,rmax=INT_MIN;
        int units = 0;
        while(l<r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax , height[r]);
            
            if(lmax<rmax){
                units += min(lmax,rmax)-height[l];
                l++;
            }
            else{
                units += min(lmax,rmax)-height[r];
                r--;
            }
        }
        return units;
    }
};