class Solution {
public:
    vector<string> ans={};
    vector<string> generateParenthesis(int n) {
        string state ="(";
        helper(1, 0, state, n);
        return ans;
    }

    void helper(int open, int closed, string& state, int n){
        if(closed==n){
            ans.push_back(state);
            return;
        }

        if(open<n){
            state+="(";
            helper(open+1, closed, state, n);
            state.pop_back();
        }

        if(closed<open){
            state+=")";
            helper(open, closed+1, state, n);
            state.pop_back();
        }
    }
};
/*
Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]
open, closed, n

( -> (( -> ((( -> 

*/
