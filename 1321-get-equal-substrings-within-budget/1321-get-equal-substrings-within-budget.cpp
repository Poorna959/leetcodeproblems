class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n= s.length();
        int l=0;
        int cost = 0;
        int max_len = INT_MIN;
        // in this you can maintain the prefix sum for the abs difference 
        for(int r=0;r<n;r++){
            if(cost<=maxCost){
                cost+=abs(s[r]-t[r]);
            }
            while(cost>maxCost){
                cost-=abs(s[l]-t[l]);
                l++;}
            
            max_len=max(max_len,r-l+1);
        }
        return (max_len==INT_MIN)?0:max_len;

    }
};