class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> memo;
        memo.push(-1);
        int ans = 0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                memo.push(i);
            }else{
                memo.pop();
                if(memo.empty()){
                    memo.push(i);
                }else{
                    ans = max(ans,i-memo.top());
                }
            }
        }    
        return ans;
    }
};