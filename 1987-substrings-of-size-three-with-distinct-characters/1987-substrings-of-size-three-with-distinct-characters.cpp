class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int l=0;
        int count = 0;
        unordered_map<char,int> memo ;
        for(int r=0;r<n;r++){
            memo[s[r]]++;
            while((r-l+1)>3){
                memo[s[l]]--;
                if(memo[s[l]]==0){
                    memo.erase(s[l]);
                }
                l++;
            }
            if(memo.size()==3)
            count++;
        }
        return count;
    }
};