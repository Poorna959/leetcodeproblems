class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> memo;
        int ans=0;
        for(auto i:nums){
            if(memo.find(i)!=memo.end()){
                ans^=i;
            }
            else{
                memo.insert(i);
                
            }
        }
        return ans;
    }
};