class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> a;
        unordered_map<string,char> b;
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
        }
         if (pattern.length() != words.size()) {
            return false;
        }
        int j=0;
        int m=s.length();
        int n=pattern.length();
        for(int i=0;i<n;i++){
            string temp = "";
            while(j<m && s[j]!=' '){
                temp+=s[j];
                j++;
            }
            j++;

            if(a.find(pattern[i])!=a.end()){
                if(b.find(temp)!=b.end()){
                if(a[pattern[i]]!=temp || b[temp]!=pattern[i]){
                    return false;
                }}
                else{
                    return false;
                }
            }
            else if(b.find(temp)!=b.end()){
                if(b[temp]!=pattern[i]){
                    return false;
                }
            }
            else{
                a[pattern[i]]=temp;
                b[temp]=pattern[i];
            }
        }
        return true;
    }
};