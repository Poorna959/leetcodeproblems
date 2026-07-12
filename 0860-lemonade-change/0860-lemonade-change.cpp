class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto i:bills){
            if(i==5){
                five+=1;
            }
            else if(i==10){
                if(five!=0){
                    five-=1;
                    ten+=1;
                }
                else return false;
            }
            else if(i==20){
                if(five!=0 & ten!=0){
                    five-=1;
                    ten-=1;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
    return true;
    }
};