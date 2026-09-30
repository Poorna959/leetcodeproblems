class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> lprefix;
        lprefix.push_back(0);
        vector<int> rprefix;
        rprefix.push_back(0);
        int score = 0;
        for(int i=0;i<n;i++){
            score+=cardPoints[i];
            lprefix.push_back(score);
        }
        score=0;
        for(int i =n-1;i>=0;i--){
            score+=cardPoints[i];
            rprefix.push_back(score);
        }
        int l=k;
        int r=0;
        int max_score = INT_MIN;
        while(l>=0 && r<=k){
            max_score  = max(max_score,lprefix[l]+rprefix[r]);
            l--;
            r++;
        }
        
        return max_score;
    }
};