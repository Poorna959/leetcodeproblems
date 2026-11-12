class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(char ch:s){
            if(ans.empty()){
                ans.push_back(ch);
            }
            else {
                if(ans.back()==ch){
                    ans.pop_back();
                }
                else{
                    ans.push_back(ch);
                }
            }
        }    
        return ans;
    }
};