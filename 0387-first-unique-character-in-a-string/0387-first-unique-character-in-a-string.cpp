class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> memo;
        int n=s.length();
        for(int i=0;i<n;i++){
            memo[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(i!=memo[s[i]]){
                memo.erase(s[i]);
            }
            else{
                return i;
            }
        }
        return -1;
    }
};