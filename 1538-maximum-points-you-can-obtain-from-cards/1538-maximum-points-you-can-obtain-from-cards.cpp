class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lprefix = 0;
        for(int i=0;i<k;i++){
            lprefix+=cardPoints[i];
        }
        int max_score = lprefix;
        for(int i=1;i<=k;i++){
            lprefix = lprefix - cardPoints[k - i] + cardPoints[n - i];
            max_score = max(max_score, lprefix);
        }
        
        return max_score;
    }
};