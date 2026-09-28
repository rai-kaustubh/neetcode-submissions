class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int row =-1;
        while(l<=r && r<matrix.size()){
            int mid = l+(r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid].back()){
                row =mid;
                break;
            } 

            if(target<matrix[mid][0]){
                r=mid-1;
            } else{
                l=mid+1;
            }
        } 
        if(row ==-1) return false;

        l=0, r=matrix[row].size()-1;
        while(l<=r && r<matrix[row].size()){
            int mid = l+(r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }

            if(target>matrix[row][mid]){
                l=mid+1;
            } else {
                r=mid-1;
            }
        }

        return false;

    }
};
/*
matrix =    [1,2,4,8],
            [10,11,12,13],
            [14,20,30,40], target = 10



*/
