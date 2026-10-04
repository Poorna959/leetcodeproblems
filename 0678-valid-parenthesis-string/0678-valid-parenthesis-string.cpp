class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;
        for(auto i:s){
            if(i=='('){
                low++;
                high++;
            }
            else if(i==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            if(high<0)return false;
            if(low<0)low=0;
        }
        if(low==0)return true;
        else return false;
    }
};