class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int ROW = m.size();
        int COL = m[0].size();
        bool isRow = false, isCol = false;
        for(int r=0;r<ROW;r++){
            for(int c =0;c<COL;c++){
                if(!m[r][c]){
                    m[r][0] = 0;
                    m[0][c] = 0;

                    if(r==0) isRow = true;
                    if(c==0) isCol = true;
                }
            }
        }

        //set col to 0
        for(int c=1;c<COL;c++){
            if(!m[0][c]){
                for(int r=1;r<ROW;r++){
                    m[r][c] = 0;
                }
            }
        }
        //set row to 0
        for(int r=1;r<ROW;r++){
            if(!m[r][0]){
                for(int c=1;c<COL;c++){
                    m[r][c] = 0;
                }
            }
        }

        if(isRow){
            for(int c=1;c<COL;c++){
                m[0][c] = 0;
            }
        }
        if(isCol){
            for(int r=1;r<ROW;r++){
                m[r][0] = 0;
            }
        }


    }
};
