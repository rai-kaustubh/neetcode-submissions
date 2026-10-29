class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> combine(int n, int k) {
        vector<int> state={};
        helper(1, n, k, state);
        return ans;
    }

    void helper(int i, int& n, int& k, vector<int>& state){
        if(i>n){
            if(state.size()==k){
                ans.push_back(state);
            }
            return;
        }

        state.push_back(i);
        helper(i+1, n,k, state);
        state.pop_back();
        helper(i+1, n,k, state);
    }
};
/*
    Input: n = 3, k = 2
    ans -> all combinantions of length k
    
    arr = 1,2,3
    state, arr, index
    
    if (state.size()==k || index==arr.size()) ans.push_back(state); return;

    state.push(arr[index]);
    rec(state, arr, index+1);
    state.pop_back()
    rec(state, arr, index+1);

    1 -> {1,2}
          -> {1,3}  




*/    