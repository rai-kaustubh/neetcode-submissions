class Solution {
public:
    int ROWS, COLS;
    int dir[4][2] = {{0,1},{-1, 0},{1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        ROWS = ht.size();
        COLS = ht[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        for(int c=0;c<COLS;c++){ // iterate row 0
            dfs(0, c, pac, ht);
        }
        for(int r=0;r<ROWS;r++){ // iterate col 0
            dfs(r, 0, pac, ht);
        }
        
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        for(int r=0;r<ROWS;r++){ // iterate last col
            dfs(r, COLS-1, atl, ht);
        }
        for(int c=0;c<COLS;c++){ // iterate last row
            dfs(ROWS-1, c, atl, ht);
        }
        // iterate over pac and atl
        // if atl[i][j] && pac[i][j], insert i,j into ans;

        vector<vector<int>> ans;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(atl[r][c] and pac[r][c]){
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& ht){
        visited[r][c]=true;

        //iterate over all directions
        for(int i=0;i<4;i++){
            int row = r+dir[i][0];
            int col = c+dir[i][1];
            
            if(row<0 or row>=ROWS or col<0 or col>=COLS or ht[row][col]<ht[r][c] or visited[row][col]) 
                continue;
            
            dfs(row, col, visited, ht);
        }
    }
};
