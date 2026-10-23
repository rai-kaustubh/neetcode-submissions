struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};
class Solution {
public:
    int ROW, COL;
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        
        bool ans=false;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(board[i][j]==word[0]){
                    set<pair<int, int>> visited;
                    visited.insert({i,j});
                    ans= dfs(i, j, 0, visited, board, word) || ans;
                }
            }
        }

        return ans;
    }

    bool dfs(int r, int c, int index, set<pair<int, int>>& visited, vector<vector<char>>& board, string& word){
        if(r>=ROW || r<0 || c<0|| c>=COL || board[r][c]!=word[index]) return false;
        
        if(index==word.size()-1 && board[r][c]==word[index]) return true;

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        bool ans = false;
        for(int i=0;i<4;i++){
            int row = r + dir[i][0];
            int col = c + dir[i][1];
            if(!visited.count({row, col})){
                visited.insert({row, col});
                ans = ans||dfs(row, col, index+1, visited, board, word);
                visited.erase({row, col});
            }
        }

        return ans;
    }
};
/*
    backtracking -> index, row, col, visited
*/
