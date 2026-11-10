class Solution {
public:
    string decodeString(string s) {
        stack<int>countstack;
        stack<string>stringstack;
        string curr="";
        int k=0;
        for(char ch:s){
            if(isdigit(ch)){
                k=k*10+ch-'0';
            }
            else if(ch=='['){
                countstack.push(k);
                stringstack.push(curr);
                curr="";
                k=0;
            }
            else if(ch==']'){
                string prevstring = stringstack.top();
                stringstack.pop();
                int repeate  = countstack.top();
                countstack.pop();
                string repstring = "";
                for(int i=0;i<repeate;i++){
                    repstring +=curr;
                }
                curr = prevstring +repstring;
            }
            else{
                curr+=ch;
            }
        }
        return curr;
    }
};