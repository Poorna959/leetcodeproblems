class Solution {
private:
        bool ignoring(string &s,int l,int r){
            while(l<=r){
                if(s[l]!=s[r]){
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        if(n==1 || n==2){
            return true;
        }
        bool ignore1 = true,ignore2=true;
        int l = 0,r=n-1;
        while(l<=r){
            if(s[l]!=s[r]){
            ignore1 = ignoring(s,l+1,r);
            ignore2 = ignoring(s,l,r-1);
            return ignore1 || ignore2;
            }
            l++;
            r--;

            
        } return true;} 
};