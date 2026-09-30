class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int l=0,r=0;
        int max_vowel = INT_MIN;
        int vowel=0;
        while(r<n){
            while(r<n && r-l+1<=k ){
                if(s[r]=='a' || s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u' ){
                    vowel++;
                }
                r++;
            }
            max_vowel = max(max_vowel,vowel);
            if(s[l]=='a' || s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u' ){
                vowel--;
                l++;
            }
            else{
            l++;}
        }
        return max_vowel;
    }
};