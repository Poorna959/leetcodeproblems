class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(s.empty() || nums[s.top()]>nums[i]){
                s.push(i);
            }
        }

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                ans = max(ans,i-s.top());
                s.pop();
            }
        }
        return ans;
    }
};