class Solution {
public:
    int clumsy(int n) {
        long long currnum = n-1;
        long long lastnum = n;
        long long sum =0;
        int j=1;
        int i = 0;
        vector<char> op={'*','/','+','-'};
        char lo = op[i%op.size()];
        while(currnum!=0){
            
            if (lo == '+') {
                    sum += lastnum;
                    lastnum = currnum;
                } 
                else if (lo == '-') {
                    sum += lastnum;
                    lastnum = -currnum;
                } 
                else if (lo == '*') {
                    lastnum = lastnum * currnum;
                } 
                else if (lo == '/') {
                    lastnum = lastnum / currnum; // C++ truncates towards zero by default
                }
                i++;
                j++;
                lo = op[i%op.size()];
                currnum = n-j;
            }
            sum += lastnum;
            return static_cast<int>(sum);
        }
    };