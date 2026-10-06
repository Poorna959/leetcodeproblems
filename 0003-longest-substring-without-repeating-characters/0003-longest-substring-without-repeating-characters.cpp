class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==1)return 1;
        if(n==0)return 0;
        int max_ans = 0;
        int l=0;
        vector<char> lastseen(256,-1);
        for(int r=0;r<n;r++){
                if(lastseen[s[r]]>=l){
                    l= lastseen[s[r]]+1;
                }
                lastseen[s[r]]=r;
                max_ans=max(max_ans,r-l+1);
            }
            return max_ans;
    }
};