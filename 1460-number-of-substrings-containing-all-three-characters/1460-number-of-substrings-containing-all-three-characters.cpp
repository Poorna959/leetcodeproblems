class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count= 0;
        int l=0;
        vector<int> memo(3,0);
        for(int r =0;r<n;r++){
            memo[s[r]-'a']++;
            while(memo[0]>0 && memo[1]>0 && memo[2]>0){
                count+=(n-r);
                memo[s[l]-'a']--;
                l++;
            }
        }
        return count;
    }

};