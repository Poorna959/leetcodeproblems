class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int ans=0;
        unordered_map<int,int> memo;
        for(int r=0;r<n;r++){
            memo[fruits[r]]++;
            while(memo.size()>2){
                memo[fruits[l]]--;
                if(memo[fruits[l]]==0){
                    memo.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans,r-l+1);
        }
        return ans;
    }
};