class Solution {
public:
    string minWindow(string s, string t) {
        if(s=="" || t=="")return "";
        int n = s.length();
        int m = t.length();
        if(n<m)return "";
        unordered_map<char,int> t_store;
        for(char ch:t){
            t_store[ch]++;
        }
        int l=0;
        int ans=INT_MAX;
        int total_char = 0;
        unordered_map<char,int>store;
        int min_l=0;
        
        for(int r=0;r<n;r++){
            store[s[r]]++;
            if(t_store.count(s[r])!=0 && store[s[r]]<=t_store[s[r]]){
                total_char++;
            }
            while(total_char==m){
                    if(r-l+1<ans){
                        min_l=l;
                        ans = r-l+1;
                    }
                    if(t_store.count(s[l]) && store[s[l]]<=t_store[s[l]]){
                        total_char--;
                    }
                    store[s[l]]--;
                    if(store[s[l]]==0){
                        store.erase(s[l]);
                    }
                    l++;
            }
        }
        

        return (ans==INT_MAX)?"":s.substr(min_l,ans);

    }
};