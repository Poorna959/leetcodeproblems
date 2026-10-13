class Solution {
private:
    int atmost(vector<int>& nums, int bound){
        int currlength = 0;
        int count = 0;
        for(int n:nums){
            if(n<=bound){
                currlength++;
                count+=currlength;
            }
            else{
                currlength = 0;
            }
        }
        return count;
    }
public:

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return atmost(nums,right)-atmost(nums,left-1);
    }
};