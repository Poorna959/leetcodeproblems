class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l =0;
        int max_ans = INT_MIN;
        unordered_map<int,int> memo;
        for(int r=0;r<n;r++){
            memo[fruits[r]]++;
            while(l<r && memo.size()>2){
                memo[fruits[l]]--;
                
                if(memo[fruits[l]]==0){
                    memo.erase(fruits[l]);
                }
                l++;
                
            }
            max_ans = max(max_ans,r-l+1);
        }
        return max_ans;
    }
};