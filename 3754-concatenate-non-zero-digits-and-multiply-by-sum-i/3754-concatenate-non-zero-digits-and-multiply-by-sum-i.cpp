class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        int a=0;
        while(n!=0){
            int digit =n%10;
            if(digit!=0){
                if(x==0){
                x=digit;;
                sum+=digit;a=10;}
                else{
                    x=(digit*a)+x;
                    sum+=digit;
                    a*=10;
                }
            }
            n=n/10;
        }
        return x*sum;
    }
};