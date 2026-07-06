class Solution {
public:
    void nextPermutation(vector<int>& nums) { 
    int pivot = -1; 
    int n = nums.size(); 
    
    // step 1: Start at n - 2 to prevent out-of-bounds access
    for(int i = n - 2; i >= 0; i--) { 
        if(nums[i] < nums[i + 1]) { 
            pivot = i; 
            break; 
        } 
    } 
    
    if(pivot == -1) { 
        reverse(nums.begin(), nums.end()); 
        return; 
    } 
    
    // step 2: Add break statement after the first valid swap
    for(int i = n - 1; i > pivot; i--) { 
        if(nums[i] > nums[pivot]) { 
            swap(nums[pivot], nums[i]); 
            break; 
        } 
    } 
    // step 3: revesre the remaining elements
    int i = pivot + 1, j = n - 1; 
    while(i < j) { 
        swap(nums[i++], nums[j--]); 
    } 
}

};