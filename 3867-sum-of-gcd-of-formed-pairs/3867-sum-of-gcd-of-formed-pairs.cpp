class Solution {
public:
    int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int max_num=INT_MIN;
        for(int i=0;i<nums.size();i++){
            max_num=max(max_num,nums[i]);
            int gcdnum=GCD(nums[i],max_num);
            prefixGcd.push_back(gcdnum);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0,r=prefixGcd.size()-1;
        long long sum=0;
        while(l<r){
            sum+=GCD(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};