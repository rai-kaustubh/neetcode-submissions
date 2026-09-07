class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board (n, string(n,'.')) ;
        dfs(0, board,n);
        return ans;
    }

    void dfs(int r, vector<string>& board, int n){
        if(r==board.size()){
            ans.push_back(board);
            return;
        }

        for(int c=0;c<n;c++){
            if(isSafe(r,c, n, board)){
                board[r][c]='Q';
                dfs(r+1, board,n);
                board[r][c]='.';
            }
        }

        return;
    }

    bool isSafe(int row, int col, int n, vector<string>& board){
        for(int r = row-1;r>=0;r--){ // vertical check
            if(board[r][col]=='Q') return false;
        }

        for(int r=row-1, c = col-1;r>=0 and c>=0;r--,c--){
            if(board[r][c]=='Q') return false;
        }
        for(int r=row-1, c = col+1;r>=0 and c<n;r--,c++){
                if(board[r][c]=='Q') return false;
        }

        return true;
    }


};
