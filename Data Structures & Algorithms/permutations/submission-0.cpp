class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> _set(nums.begin(), nums.end());
        for(auto x: _set){ cout<<x<<" ";}
        vector<int> state;
        dfs(state, _set);
        return ans;
    }
    void dfs(vector<int>& state, unordered_set<int>& _set){
        if(_set.size()==0){
            ans.push_back(state);
            return;
        }

        unordered_set<int> temp = _set;

        for (auto x : temp) {
            state.push_back(x);

            _set.erase(x);
            dfs(state, _set);

            _set.insert(x);
            state.pop_back();
        }
    }
};
