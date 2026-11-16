class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a= "";
        string b = "";
        for(char ch:s){
            if(a.empty() && ch=='#'){
                continue;
            }
            if(!a.empty() && ch=='#'){
                a.pop_back();
            }
            else{
                a.push_back(ch);
            }
        }
        for(char ch:t){
            if(b.empty() && ch=='#')continue;
            if(!b.empty() && ch=='#'){
                b.pop_back();
            }
            else{
                b.push_back(ch);
            }
        }
        return a==b;
    }
};