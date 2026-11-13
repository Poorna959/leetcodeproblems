class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> memo;
        int n = s.length();
        for(int i=0;i<n;i++){
            memo[s[i]]=i;
        }
        string ans = "";
        unordered_map<char,bool> visited;
        for(int i=0;i<n;i++){
            if(visited[s[i]])continue;
            while(!ans.empty() && ans.back()>=s[i] && memo[ans.back()]>i){
                visited[ans.back()]=false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            visited[s[i]]=true;
        }
        return ans;
    }
};