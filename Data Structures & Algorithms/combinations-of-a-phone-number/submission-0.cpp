class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> res;
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string& digits, int i, string state){
        if(state.length()==digits.length()){
            res.push_back(state);
            return;
        }

        for(char c: digitToChar[digits[i]-'0']){
            state+=c;
            dfs(digits, i+1, state);
            state.pop_back();
        }
    }
};
