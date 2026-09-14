class Solution {
public:
    int ROW, COL;
    void rotate(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix.size();
        transpose(matrix);
        _reverse(matrix);
    }

    void transpose(vector<vector<int>>& m){
        for(int i=0;i<ROW;i++){
            int r =i;
            for(int c=i;c<COL;c++){
                swap(m[r][c],m[c][r]);
            }
        }

        // for(int r=0;r<ROW;r++){
        //     for(int c=0;c<COL;c++){
        //         cout<<m[r][c]<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    void _reverse(vector<vector<int>>& m){
        for(int r=0;r<ROW;r++){
            int l = 0,ri=COL-1;
            while(l<=ri){
                swap(m[r][l], m[r][ri]);
                l++;
                ri--;
            }
        }


        // for(int r=0;r<ROW;r++){
        //     for(int c=0;c<COL;c++){
        //         cout<<m[r][c]<<" ";
        //     }
        //     cout<<endl;
        // }
    }


};
