class Solution {
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        int l=0;int r=x/2;
        while(l<=r){
            long long m = l+(r-l)/2;
            long long s = m*m;
            if(s==x){
                return m;
            }
            else if(s<x){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return r;

    }
};