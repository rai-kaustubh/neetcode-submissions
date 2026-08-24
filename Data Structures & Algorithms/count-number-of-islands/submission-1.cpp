class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        // iterate all elements
        // if element ==1, increase island count, do its dfs
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]=='1'){
                    islands++;
                    dfs(r,c, grid);
                }
            }
        }

        return islands;
    }

    void dfs(int r, int c, vector<vector<char>>& grid){
        if (r>=grid.size() || r<0 || c>=grid[0].size() || c<0 || grid[r][c]=='0')
            return;
        
        //mark curr node as visited (0);
        grid[r][c]='0';
        //iterate over the directions
        for(int i=0;i<4;i++){
        //if grid[i][j]==1, dfs(i, j, grid)
            dfs(r+dir[i][0],c+dir[i][1] , grid);
        }
    }

};
