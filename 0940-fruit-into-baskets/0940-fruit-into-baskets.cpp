class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> memo;
        int max_fruits = INT_MIN;
        int l = 0;
        for(int r=0;r<n;r++){
            memo[fruits[r]]++;
            while(memo.size()>2){
                memo[fruits[l]]--;
                if(memo[fruits[l]]==0){
                    memo.erase(fruits[l]);
                }
                l++;
            }
            max_fruits = max(max_fruits,r-l+1);

        }
        return max_fruits;
    }
};