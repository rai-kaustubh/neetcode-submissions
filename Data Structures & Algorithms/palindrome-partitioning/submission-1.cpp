class Solution {
public:
    vector<vector<string>> ans={};
    
    vector<vector<string>> partition(string s) {
        vector<string> state={};
        helper(s, 0, state)   ; 
        return ans;
    }

    void helper(string& s, int index, vector<string>& state){
        if(index>=s.size()){
            ans.push_back(state);
            return;
        }

        for(int i=index+1;i<=s.size();i++){
            string substr = s.substr(index, i-index);
            if(isPalindrome(substr)){
                state.push_back(substr);
                helper(s, i, state);
                state.pop_back();
            }
        }

        return;
    }

    bool isPalindrome(string s) {
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
/*
    aab
    index = 1;
    i=1
    a,
*/
