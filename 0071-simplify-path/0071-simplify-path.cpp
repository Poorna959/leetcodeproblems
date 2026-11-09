class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        int n = path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                continue;
            }
            string temp="";
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                ++i;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if (!s.empty()) {
                    s.pop();
                }
            }
            else{
                s.push(temp);
            }
            
        }
        string ans = "";
        while(!s.empty()){
        ans = '/'+s.top()+ans;
        s.pop();
        }
        if(ans.size()==0){
            return "/";
        }
        return ans;
    }
};