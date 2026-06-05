class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = findRow(matrix, target);
        if(row!=-1){
            return findNum(row, matrix, target)>-1;
        }

        return false;
    }

    int findRow(vector<vector<int>>& matrix, int target){
        int l=0,r=matrix.size()-1;

        while(l<=r){
            int mid = l+ (r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[mid].size()-1]){
                return mid;
            }
            if(matrix[mid][matrix[mid].size()-1]>target){
                r=mid-1;
                continue;
            }
            l=mid+1;
        }

        return -1;
    }

    int findNum(int row, vector<vector<int>>& matrix, int target){
        int l=0,r=matrix[row].size()-1;

        while(l<=r){
            int mid = l+ (r-l)/2;
            if(matrix[row][mid]==target){
                return mid;
            }
            if(matrix[row][mid]>target){
                r=mid-1;
                continue;
            }
            l=mid+1;
        }

        return -1;

    }
};
