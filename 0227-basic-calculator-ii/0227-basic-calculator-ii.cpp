#include <string>
#include <cctype>

class Solution {
public:
    int calculate(std::string s) {
        if (s.empty()) return 0;
        
        long long currentNumber = 0;
        long long lastNumber = 0;
        long long totalSum = 0;
        char lastOperator = '+';
        
        // Add a dummy operator at the end to trigger processing of the final number
        s += '+';
        
        for (char ch : s) {
            if (std::isdigit(ch)) {
                currentNumber = (currentNumber * 10) + (ch - '0');
            } 
            else if (ch != ' ') {
                // Process the completed number based on the preceding operator
                if (lastOperator == '+') {
                    totalSum += lastNumber;
                    lastNumber = currentNumber;
                } 
                else if (lastOperator == '-') {
                    totalSum += lastNumber;
                    lastNumber = -currentNumber;
                } 
                else if (lastOperator == '*') {
                    lastNumber = lastNumber * currentNumber;
                } 
                else if (lastOperator == '/') {
                    lastNumber = lastNumber / currentNumber; // C++ truncates towards zero by default
                }
                
                lastOperator = ch;
                currentNumber = 0;
            }
        }
        
        totalSum += lastNumber;
        return static_cast<int>(totalSum);
    }
};
