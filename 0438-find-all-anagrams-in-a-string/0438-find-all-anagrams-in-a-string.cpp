class Solution {

public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        if(m<n){
            return {};
        }
        vector<int> freq(26);
        vector<int> wind(26);
        for(int i=0;i<n;i++){
            freq[p[i]-'a']++;
            wind[s[i]-'a']++;
        }
        vector<int> ans;
        if(freq==wind){
            ans.push_back(0);
        }

        for(int i=n;i<m;i++){
            wind[s[i-n]-'a']--;
            wind[s[i]-'a']++;
            if(wind==freq){
                ans.push_back(i-n+1);
            }
        }
        return ans;
    }
};