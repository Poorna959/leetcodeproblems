class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        for(int n :asteroids){
            bool destroyed = false;
            while(!ans.empty() && ans.back()>0 && n<0 ){
                if(ans.back()<-n){
                    ans.pop_back();
                }
                else if(ans.back()==-n){
                    destroyed = true;
                    ans.pop_back();
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                ans.push_back(n);
            }
            
            
        }
        return ans;
    }
};