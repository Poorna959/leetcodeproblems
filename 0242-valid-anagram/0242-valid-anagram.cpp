class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        vector<int> memo1(26);
        vector<int> memo2(26);
        for(int i=0;i<s.length();i++){
            memo1[s[i]-'a']++;
            memo2[t[i]-'a']++;
        }   
        for(int i=0;i<26;i++){
            if(memo1[i]!=memo2[i]){
                return false;
            }
        }return true;
        
    }
};