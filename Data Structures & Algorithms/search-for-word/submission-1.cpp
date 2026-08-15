class Solution {
public:
    bool res;
    bool exist(vector<vector<char>>& board, string word) {
        res=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                auto temp = board[i][j];
                if(board[i][j]==word[0]){
                    board[i][j]='#';
                    if(dfs(board, word, 1, i, j)) 
                        return true;
                }
                board[i][j]=temp;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int idx, int row, int colm){
        if(idx>=word.length()) { return true;}

        int rows[]={0,0,1,-1};
        int colms[]={1, -1, 0, 0};

        for(int i=0;i<4;i++){
            int r = row+rows[i];
            int c = colm+colms[i];

            if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c] !='#'){
                
                auto temp = board[r][c];
                if(board[r][c]==word[idx]){
                    board[r][c]='#';
                    if (dfs(board, word, idx+1, r, c)){
                        return true;
                    }
                }
                board[r][c]=temp;

            }
        }

        return false;
    }
};
