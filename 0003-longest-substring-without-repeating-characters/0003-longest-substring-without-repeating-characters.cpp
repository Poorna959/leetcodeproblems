class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int   n = s.size();
        int  l =0;
        int max_len = 0;
        unordered_map<char,int>memo;
        for(int r=0;r<n;r++){
            memo[s[r]]++;
            while(memo[s[r]]==2){
                memo[s[l]]--;
                if(memo[s[l]]==0){
                    memo.erase(s[l]);
                }
                l++;
            }

            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};