class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<int> set;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    //found duplicate
                    if(set.find(board[i][j])!=set.end())
                        return false;
                    
                    set.insert(board[i][j]);
                }
            }    
        } 
        for(int i=0;i<9;i++){
            unordered_set<int> set;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    //found duplicate
                    if(set.find(board[j][i])!=set.end())
                        return false;
                    
                    set.insert(board[j][i]);
                }
            }    
        } 

        for(auto sq=0;sq<9;sq++){
            unordered_set<char> set;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row= (sq/3)*3+i;
                    int col= (sq%3)*3+j;
                    if(board[row][col]!='.'){
                    //found duplicate
                    if(set.find(board[row][col])!=set.end())
                        return false;
                    
                    set.insert(board[row][col]);}
                }
            }
        }

        return true;

    }
};