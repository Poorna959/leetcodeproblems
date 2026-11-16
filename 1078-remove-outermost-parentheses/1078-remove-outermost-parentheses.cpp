class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int st = 0;
        string temp = "";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st++;
                temp+=s[i];
            }
            else{
                st--;
                temp+=s[i];
            }
            if(st==0){
                string flag = temp.substr(1, temp.length() - 2);
                ans+=flag;
                temp="";
            }
        
        }
        return ans;
    }
};