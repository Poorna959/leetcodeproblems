class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> a;
        unordered_map<char,char> b;

        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        for(int i=0;i<n;i++){
             if (a.find(s[i])!=a.end() && a[s[i]] != t[i]) {
                return false;
            }
            if (b.find(t[i])!=b.end() && b[t[i]]!= s[i]) {
                return false;
            }
            a[s[i]]=t[i];
            b[t[i]]=s[i];
        }
        return true;
    }
};