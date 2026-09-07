class Solution {
public:
    vector<string> vec = {"", "","abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        
        dfs(0, "", digits);
        return ans;
    }

    void dfs(int j, string state, string& digits){
        if(state.size()==digits.size()){
            ans.push_back(state);
            return ;
        }

        for(int i=j;i<digits.size();i++){
            for(char c: vec[digits[i]-'0']){
                state+=c;
                dfs(i+1, state, digits);
                state.pop_back();
            }
        }
    }
};
