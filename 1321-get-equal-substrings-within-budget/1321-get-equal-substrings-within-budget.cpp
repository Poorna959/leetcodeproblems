class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int l=0;
        int count = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            count+=abs(s[r]-t[r]);
            while(count>maxCost){
                int cost = abs(s[l]-t[l]);
                count-=cost;
                l++;
            }

            if(count<=maxCost){
                ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};