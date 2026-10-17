class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        // int l=0;
        // int count = 0;
        // unordered_map<char,int> memo ;
        // for(int r=0;r<n;r++){
        //     memo[s[r]]++;
        //     while((r-l+1)>3){
        //         memo[s[l]]--;
        //         if(memo[s[l]]==0){
        //             memo.erase(s[l]);
        //         }
        //         l++;
        //     }
        //     if(memo.size()==3)
        //     count++;
        // }
        // return count;

        if(n<3){
            return 0;
        }
        int count=0;
        for(int i=0;i<=n-3;i++){
             if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
                count++;
            }
        }
        return count;
    }
};