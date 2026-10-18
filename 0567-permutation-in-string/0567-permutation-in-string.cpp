class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m){
            return false;
        }
        vector<int> memo1(26);
        vector<int>memo2(26);
        for(int i=0;i<n;i++){
            memo1[s1[i]-'a']++;
            memo2[s2[i]-'a']++;
        }
        if(memo1==memo2){
            return true;
        }
        for(int i =n;i<m;i++){
            memo2[s2[i-n]-'a']--;
            memo2[s2[i]-'a']++;
            if(memo2==memo1){
                return true;
            }
        }
        return false;
    }
};