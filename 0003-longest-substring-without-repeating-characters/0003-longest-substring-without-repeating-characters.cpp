class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)return 0;
        if(n==1)return 1;
        int max_len=INT_MIN;
        vector<int> lastseen(256,-1);
        int left=0;
        
        for(int right=0;right<s.length();right++){
            char current_char=s[right];
            if(lastseen[current_char]>=left){
                left = lastseen[current_char]+1;
            }
            lastseen[current_char]=right;
            max_len=max(max_len,right-left+1);
        }
    return max_len;}
};