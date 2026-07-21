class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int ghost_tar=0,me_tar=0;
        me_tar=abs(target[0]-0)+abs(target[1]-0);
        for(auto i:ghosts){
            ghost_tar=abs(target[0]-i[0])+abs(target[1]-i[1]);
            if(ghost_tar<=me_tar){
                return false;
            }
        }
        return true;
    }
};