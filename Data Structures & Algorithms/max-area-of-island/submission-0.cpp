class Solution {
public:
    int maxArea = 0;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // iterate grid, if grid[r][c]==1, do dfs
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    int area = 0;
                    dfs(r, c, grid, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, int &area){
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
            return;
        }

        grid[r][c]=0;
        area++;
        maxArea = max(maxArea, area);

        for(int i=0;i<4;i++){
            dfs(r+dir[i][0], c+dir[i][1], grid, area);
        }
    }
};
