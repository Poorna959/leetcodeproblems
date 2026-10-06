class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int mem=0;
        for(char c:s){
            if(c=='('){
                mem++;
                
            }else{
                if(mem<=0){
                    ans++;
                }
                else{
                    mem--;
                }
            }
        }
        return abs(mem)+ans;
    
    }
};