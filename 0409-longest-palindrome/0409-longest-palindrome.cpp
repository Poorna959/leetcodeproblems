class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> memo(128);
        for(char i:s){
            memo[i]++;
        }
        int longest=0;
        bool odd=false;
        for(int i:memo){
            longest+=(i/2)*2;
            if(i%2!=0){
                odd=true;
            }
        }
        if(odd){
            longest+=1;
        }
        return longest;
    }
};