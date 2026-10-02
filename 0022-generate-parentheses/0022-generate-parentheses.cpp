class Solution {
private:
    void ans(int n,int close,int open,string s,vector<string> &memo){
        if(s.length()==2*n){
            memo.push_back(s);
            return ;
        }
        if(open<n){
            ans(n,close,open+1,s+'(',memo);
        }
        if(close<open){
            ans(n,close+1,open,s+')',memo);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>memo;
        ans(n,0,0,"",memo);
        return memo;
    }
};