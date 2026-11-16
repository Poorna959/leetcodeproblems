class Solution {
string base(int b,int n){
    string ans = "";
    while(n!=0){
        char ch = static_cast<char>(n%b);
        ans+=ch;
        n = n/b;
    }
    return ans;
}
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            string s= base(i,n);
            string temp = s;
            reverse(s.begin(),s.end());
            if(s!=temp){
                return false;
            }
        }
        return true;
    }
};