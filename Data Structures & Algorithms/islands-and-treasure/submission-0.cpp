class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
        int ROW = grid.size();
        int COL = grid[0].size();

        queue<pair<int, int>> q;
        // iterate grid, push all 0s in the queue;
        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            // take q's front and pop;
            pair<int, int> p = q.front();
            q.pop();
            auto row = p.first;
            auto col = p.second;
            //iterate over the directoins
            for(int i=0;i<4;i++){
                int r = row+dir[i][0];
                int c = col + dir[i][1];
                
                if (r<0 or r>=ROW or c<0 or c>=COL or grid[r][c]!=INT_MAX) 
                    continue;
                
                grid[r][c] = grid[row][col]+1;
                q.push({r,c});
            }

        }
    }
};
