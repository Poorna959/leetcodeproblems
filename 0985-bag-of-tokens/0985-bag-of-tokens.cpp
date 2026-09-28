class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int  l  = 0,r=n-1;
        int score = 0;
        int max_score = 0;
        while(l<=r){
            if(power>=tokens[l]){
                score++;
                power-=tokens[l];
                l++;
                max_score=max(max_score,score);
            }
            else  if(score>=1){
                score--;
                power+=tokens[r];
                r--;
                
            }
            else {
                break;
            }
            
        }return max_score;
    }
};