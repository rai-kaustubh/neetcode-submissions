class Solution {
public:
    vector<string> ans ={};
    vector<string> arr={"", "", "abc","def", "ghi", "jkl","mno", "pqrs", "tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return ans;
        string state="";
        helper(0, state, digits);
        return ans;
    }

    void helper(int index, string& state, string& digits){
        if(index==digits.size()){
            ans.push_back(state);
            return;
        }

        for(char c: arr[digits[index]-'0']){
            state+=c;
            helper(index+1, state, digits);
            state.pop_back();
        }   
    }
};
/*
    2 -> a,b,c 
    3 -> d,e,f
    ...

    index, state, digits
    for(char c: map[digits[index]-'a']){
        state+=c;
        helper(index+1, state, digits);
        state.pop_back();
    }
*/
