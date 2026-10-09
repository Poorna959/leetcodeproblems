class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  n =s.length();
        int l=0;
        int ans = 0;
        unordered_map<char,int> memo;
        for(int r = 0;r<n;r++){
            memo[s[r]]++;
            while(memo[s[r]]==2){
                memo[s[l]]--;
                l++;
            }

            ans = max(ans,r-l+1);
        }
        return ans;
    }
};