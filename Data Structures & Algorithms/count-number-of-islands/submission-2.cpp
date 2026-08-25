class Solution {
public:
    int ROWS, COLS;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int count=0;

        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(grid[r][c]=='1'){
                    count++;
                    dfs(r, c, grid);
                }
            }
        }

        return count;
    }

    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r<0 or c<0 or r>=ROWS or c>=COLS or grid[r][c]=='0'){
            return;
        }

        grid[r][c]='0';
        for(int i=0;i<4;i++){
            int row = r+dir[i][0];
            int col = c+dir[i][1];
            dfs(row, col, grid);
        }
    }
};
