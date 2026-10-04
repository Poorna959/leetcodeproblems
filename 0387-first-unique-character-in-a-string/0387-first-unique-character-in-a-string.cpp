class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> memo;
        int n=s.length();
        for(int i=0;i<n;i++){
            memo[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(memo[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};