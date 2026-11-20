class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int  l =nums1.size();
    int r = nums2.size();
    int i=0,j=0;
    while(i<l && j<r){
        if(nums1[i]<nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<l){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<r){
        ans.push_back(nums2[j]);
        j++;
    }
    int n = r+l;
    if(n%2==0){
        double a=ans[n/2];
        double b= ans[(n/2)-1];
        return (a+b)/2;
    }
  
        return (double) ans[n/2];

    }
};