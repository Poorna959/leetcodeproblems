class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // 1. If it's an opening bracket, push to stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // 2. If it's a closing bracket
            else {
                // If stack is empty, there is no matching opening bracket
                if (st.empty()) return false;
                
                // Check if the top matches the current closing bracket
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop(); // Valid match, remove the opening bracket
                } else {
                    return false; // Mismatched brackets
                }
            }
        }
        
        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};