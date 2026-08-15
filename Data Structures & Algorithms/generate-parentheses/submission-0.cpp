class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string state = "(";
        dfs(n, 1, 0, state);
        return res;
    }

    void dfs(int& n, int open, int close, string& state){
        if(state.length() == 2*n){
            res.push_back(state);
            return;
        }

        if(open < n){
            state+="(";
            dfs(n, open+1, close, state);
            state.pop_back();
        }        

        if(open>close){
            state+=")";
            dfs(n, open, close+1, state);
            state.pop_back();
        }
    }
};
