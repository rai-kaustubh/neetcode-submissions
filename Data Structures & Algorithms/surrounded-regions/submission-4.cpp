class Solution {
public:
    int ROW, COL;
    int dir[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
    void solve(vector<vector<char>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        for(int c=0;c<COL;c++){
            if(grid[0][c]=='O'){
                dfs(0,c, grid);
            }
            if(grid[ROW-1][c]=='O'){
                dfs(ROW-1,c, grid);
            }
        }
        for(int r=0;r<ROW;r++){
            if(grid[r][COL-1]=='O'){
                dfs(r,COL-1, grid);
            }
            if(grid[r][0]=='O'){
                dfs(r,0, grid);
            }
        }

        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]=='#'){
                    grid[r][c]='O';
                } else if(grid[r][c]=='O'){
                    grid[r][c]='X';
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r<0 or c<0 or r>=ROW or c>=COL or grid[r][c]!='O'){
            return;
        }

        grid[r][c]='#';
        for(int i=0;i<4;i++){
            int row = r+dir[i][0];
            int col = c+dir[i][1];
            
            dfs(row, col, grid);
        }
    }
};
