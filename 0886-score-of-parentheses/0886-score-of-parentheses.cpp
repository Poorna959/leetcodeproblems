class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> memo;
        memo.push(0);
        for(char c:s){
            if(c=='('){
                memo.push(0);
            }
            else{
                int v = memo.top();
                memo.pop();
                int outer  =memo.top();
                memo.pop();
                memo.push(outer+max(1*1,2*v));
            }
        }
        return memo.top();
    }
};