class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(auto n:nums){
            if(count<2 || n>nums[count-2]){
                nums[count]=n;
                count+=1;
            }
        }
        return count;
    }

};