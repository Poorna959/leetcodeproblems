class Solution {
private:
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int> memo1(26);
        for(int i=0;i<n;i++){
            memo1[s1[i]-'a']++;
        }
        int ind=0;
        vector<int> memo2(26);
        for(int i=0;i<m;i++){
            memo2[s2[i]-'a']++;
            if(i>=n){
                memo2[s2[i-n]-'a']--;
        }
            if(memo1==memo2){
                return true;
            }
        }

        return false;
    }
};