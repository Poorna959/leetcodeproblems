class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int n= blocks.size();
       int ans=0;
       for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                ans++;
            }
       }
       int max_ans= ans;
       for(int i=k;i<n;i++){
        if(blocks[i]=='B'){
            if(blocks[i-k]=='W'){
                ans--;
            }
        }
        else{
            if(blocks[i-k]=='B'){
                ans++;
            }
        }
        max_ans = min(max_ans,ans);   
       }
       return max_ans;
    }
};