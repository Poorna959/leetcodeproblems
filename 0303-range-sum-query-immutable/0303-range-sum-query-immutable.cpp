class NumArray {
private:
    vector<int> ans;
public:
    NumArray(vector<int>& nums) {
        int total=0 ;
        for(auto i:nums){
            total+=i;
            ans.push_back(total);
    }
    }
    
    int sumRange(int left, int right){
        
        if(left==0)return ans[right];
        

        return ans[right]-ans[left-1];
        

        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */