class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> memo;
        memo['I']=1;
        memo['V']=5;
        memo['X']=10;
        memo['L']=50;
        memo['C']=100;
        memo['D']=500;
        memo['M']=1000;
        int n=s.length();
        if(n==1){
            return memo[s[0]];
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(memo[s[i]]<memo[s[i+1]]){
                total+=memo[s[i+1]]-memo[s[i]];
                i++;
            }
            else{total+=memo[s[i]];}
        }
        return total;
    }
};