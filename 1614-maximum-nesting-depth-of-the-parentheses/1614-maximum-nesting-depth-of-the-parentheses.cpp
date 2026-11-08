class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int a = 0;
        for(auto ch:s){
            if(ch=='('){
                ans++;  
            }
            else if(ch==')'){
                ans--;
            }
            a = max(a,ans);
        }
        return a;
    }
};