class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int ans = 0;
        int l=0;
        int count[2]={0,0};
        int temp=0;
        for(int r=0;r<n;r++){
            char curr = answerKey[r];
            temp = max(temp , ++count[answerKey[r]=='T']);

            while((r-l+1)-temp >k){
                count[answerKey[l]=='T']--;
                l++;
            }

            ans = max(ans,r-l+1);
        }
        return ans;
    }
};