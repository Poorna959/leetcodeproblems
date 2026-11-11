class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch=='a'){
                st.push(ch);
            }
            else if(ch=='b' && !st.empty() && st.top()=='a')
                st.push(ch);
            else if(ch=='c' && st.size()>=2){
                char n1 = st.top();
                st.pop();
                char n2 = st.top();
                st.pop();
                if(n1 !='b' || n2!='a'){
                    return false;
                }
            }
            else return false;
        }
        return st.empty();
    }
};