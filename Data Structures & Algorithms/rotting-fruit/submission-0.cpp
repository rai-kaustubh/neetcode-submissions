class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // multi-src bfs with rotten oranges;

        queue<pair<int,int>> q;
        int ROW = grid.size();
        int COL = grid[0].size();

        //iterate of the grid and push all rotten oranges in the queue;
        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }
        q.push({-1, -1});
        
        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        
        auto time=0;

        while(!q.empty()){
            auto row = q.front().first;
            auto col = q.front().second;
            q.pop();
            if(row==-1){
                time++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
                continue;
            }

            //itrate over the directoins arr
            for(int i=0;i<4;i++){
                auto r = row+dir[i][0];
                auto c = col+dir[i][1];

                if(r<0 || r>=ROW || c<0 || c>=COL || grid[r][c]==2 || grid[r][c]==0){
                    continue;
                }

                grid[r][c]=2;
                q.push({r,c});
            }

        }

        // iterate over the grid
        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]==1){
                    return -1;
                }
            }
        }

        return time-1;
        
    }
};
