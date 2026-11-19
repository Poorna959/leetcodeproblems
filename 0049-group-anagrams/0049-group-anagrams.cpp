class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string,int>memo;
        for(auto s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(memo.find(temp)!=memo.end()){
                ans[memo[temp]].push_back(s);
            }
            else{
                ans.push_back({s});
                memo[temp]=ans.size()-1;
            }
        }
        return ans;
    }
};