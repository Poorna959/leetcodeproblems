class Solution {
private:
    int getPrecedence(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
public:
    int calculate(string s) {
        
        vector<string> postfix;
        stack<char> opStack;
        
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            
            
            if (isdigit(s[i])) {
                string num = "";
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                postfix.push_back(num);
            } 
            
            else {
                while (!opStack.empty() && getPrecedence(opStack.top()) >= getPrecedence(s[i])) {
                    postfix.push_back(string(1, opStack.top()));
                    opStack.pop();
                }
                opStack.push(s[i]);
                i++;
            }
        }
        
        
        while (!opStack.empty()) {
            postfix.push_back(string(1, opStack.top()));
            opStack.pop();
        }
        
        
        stack<long long> evalStack;
        
        for (const string& token : postfix) {
            
            if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                long long val2 = evalStack.top(); evalStack.pop();
                long long val1 = evalStack.top(); evalStack.pop();
                
                char op = token[0];
                if (op == '+') evalStack.push(val1 + val2);
                else if (op == '-') evalStack.push(val1 - val2);
                else if (op == '*') evalStack.push(val1 * val2);
                else if (op == '/') evalStack.push(val1 / val2);
            } 
            
            else {
                evalStack.push(stoll(token));
            }
        }
        
        return static_cast<int>(evalStack.top());
    }
};