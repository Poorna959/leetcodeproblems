class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first_max=INT_MIN,second_max=INT_MIN;
        for(auto i:nums){
            if(i>=first_max){
                second_max=first_max;
                first_max=i;
            }
            else if(i>=second_max)second_max=i;
        }
        return (first_max-1)*(second_max-1);
    }
};