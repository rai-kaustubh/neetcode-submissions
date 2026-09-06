class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r= 0;r<board.size();r++){
            for(int c= 0;c<board[0].size();c++){
                if(board[r][c]==word[0] && dfs(0, r,c,word, board)){
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int j, int r, int c , string word, vector<vector<char>>& grid){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!=word[j] || grid[r][c]=='#'){
            return false;
        }

        if(j==word.size()-1 and grid[r][c]==word[j]) return true;

        auto ch = grid[r][c];
        grid[r][c]='#';
        auto res =dfs(j+1, r+1,c,word, grid)||
                dfs(j+1, r-1,c,word, grid)||
                dfs(j+1, r,c+1,word, grid)||
                dfs(j+1, r,c-1,word, grid);
        grid[r][c] = ch;
        return res;
    }
};
