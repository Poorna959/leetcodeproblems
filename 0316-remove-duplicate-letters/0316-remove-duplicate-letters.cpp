class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> memo;
        unordered_map<char,bool> visited;
        int n = s.length();
        string st ="";
        for(int i = 0;i<n;i++){
            memo[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(visited[s[i]]){
                continue;
            }
            while(!st.empty() && st.back()>s[i] && memo[st.back()]>i){
                visited[st.back()]=false;
                st.pop_back();
            }
            st.push_back(s[i]);
            visited[s[i]]=true;
        }
        
        return st;
    }
};