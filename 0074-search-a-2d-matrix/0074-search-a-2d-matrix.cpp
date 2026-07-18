class Solution {
public:
    bool searchinROW(vector<vector<int>>& matrix,int target,int row){
        int n=matrix[0].size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(target>matrix[row][mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sr=0,er=matrix.size()-1;
        int n=matrix[0].size();
        while(sr<=er){
            int mid=sr+(er-sr)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][n-1]){
                return searchinROW(matrix,target,mid);  
            }
            else if(target>matrix[mid][n-1]){
                sr=mid+1;
            }
            else{
                er=mid-1;
            }
        }
    return false;
    }
};