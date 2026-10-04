class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int>b;
        for(auto i: magazine){
            b[i]++;
        }
        for(char i:ransomNote){
            if(b.find(i)!=b.end()){
                b[i]--;
                if(b[i]==0){
                    b.erase(i);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};