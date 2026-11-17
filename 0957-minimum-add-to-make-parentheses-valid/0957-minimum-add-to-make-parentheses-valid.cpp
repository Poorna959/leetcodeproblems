class Solution {
public:
    int minAddToMakeValid(string s) {
        int st=0;
        int count = 0;
        for(char ch:s){
            if(ch=='('){
                st++;
            }
            else{
                if(st==0){
                    count++;
                }
                else{
                st--;
                }
            }
        }
        return abs(st+count);
    }
};