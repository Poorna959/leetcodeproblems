class Solution {
private:
    bool check(vector<int>  &memo1,vector<int> &memo2){
        for(int i=0;i<26;i++){
            if(memo1[i]!=memo2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int> memo1(26);
        for(int i=0;i<n;i++){
            memo1[s1[i]-'a']++;
        }

        for(int i=0;i<m;i++){
            int windind = 0,ind=i;
            vector<int> memo2(26);
            while(windind<n && ind<m){
                memo2[s2[ind]-'a']++;
                windind++;ind++;
            }
            if(check(memo1,memo2)){
                return true;
            }
        }
        return false;
    }
};