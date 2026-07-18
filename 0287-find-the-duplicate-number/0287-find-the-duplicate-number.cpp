class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;



    //     int n=nums.size();
    //     unordered_set<int> memo;
    //     for(int i=0;i<n;i++){
    //         if(memo.find(nums[i])!=memo.end()){
    //             return nums[i];
    //         }
    //         memo.insert(nums[i]);
    //     }
    // return -1;
    }
};