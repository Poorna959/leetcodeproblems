class Solution {
public:
    string minWindow(string s, string t) {
        if(s=="" || t=="")return "";
        int n = t.length();
        unordered_map<char,int> memot;
        for(char c:t){
            memot[c]++;
        }
        int have =0,need = memot.size();
        int best = INT_MAX;
        unordered_map<char,int>memos;
        int l = 0;
        int start = 0;int m = s.length();
        for(int r=0;r<m;r++){
            char ch = s[r];
            memos[ch]++;
            if(memot.count(ch) && memot[ch]==memos[ch]){
                have++;
            }
            while(need==have){
                if(r-l+1<best){
                    best = r-l+1;
                    start = l;
                }
                if(memot.count(s[l])&& memot[s[l]]==memos[s[l]]){
                    have--;
                }
                memos[s[l]]--;
                l++;
            }
        }
        return (best==INT_MAX)?"":s.substr(start,best);
    }
};