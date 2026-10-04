class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> memo;
        for(int i:nums1){
            memo[i]++;;
        }
        vector<int> ans;
        for(int i:nums2){
            if(memo.find(i)!=memo.end()){
                memo[i]--;
                if(memo[i]==0){
                    memo.erase(i);
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};