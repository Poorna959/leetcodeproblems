class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        int count=0;
        for(char n:num){
            while (!st.empty() && st.back() > n && k > 0) {
                st.pop_back();
                k--;
            }
            st.push_back(n);

        }
        while(k>0){
            st.pop_back();
            k--;
        }
        int start = 0;
        while (start < st.length() && st[start] == '0') {
            start++;
        }
        st = st.substr(start);

        
        return st.empty() ? "0" : st;
    }
};