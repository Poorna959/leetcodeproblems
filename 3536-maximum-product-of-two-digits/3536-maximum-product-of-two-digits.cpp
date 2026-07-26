class Solution {
public:
    int maxProduct(int n) {
        int first_max=INT_MIN,second_max=INT_MIN;
        while(n!=0){
            int digit=n%10;
            if(digit>=first_max){
                second_max=first_max;
                first_max=digit;
            }
            else if(digit>=second_max)second_max=digit;
            n/=10;
        }
        return first_max*second_max;
    }
};