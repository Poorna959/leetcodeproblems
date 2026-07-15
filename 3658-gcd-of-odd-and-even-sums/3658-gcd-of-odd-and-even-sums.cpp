class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even =n*(n+1);
        int odd=n*n;
        return findGCD(odd,even);
    }
    int findGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
};