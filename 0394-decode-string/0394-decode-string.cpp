#include <iostream>
#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> countStack;
        std::stack<std::string> stringStack;
        std::string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (std::isdigit(ch)) {
                
                k = k * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // Save current state before entering nested level
                countStack.push(k);
                stringStack.push(currentString);
                
                // Reset state for the new bracket level
                currentString = "";
                k = 0;
            } 
            else if (ch == ']') {
                
                std::string prevString = stringStack.top();
                stringStack.pop();
                
                int repeatTimes = countStack.top();
                countStack.pop();

                std::string repeated = "";
                for (int i = 0; i < repeatTimes; ++i) {
                    repeated += currentString;
                }

                currentString = prevString + repeated;
            } 
            else {
            
                currentString += ch;
            }
        }

        return currentString;
    }
};