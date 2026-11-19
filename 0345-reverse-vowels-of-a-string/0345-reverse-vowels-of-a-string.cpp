class Solution {
public:
    string reverseVowels(string s) {
        int l =0;
        int r=s.length()-1;
        while(l<r){
            while(l<r && !isvowel(s[l])){
                l++;
            }
            while(l<r && !isvowel(s[r])){
                r--;
            }
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
    bool isvowel(char ch){
        if(tolower(ch)=='a' || tolower(ch)=='e' || tolower(ch)=='i' ||tolower(ch)=='o'||tolower(ch)=='u'){
            return true;
        }
        return false;
    }
};