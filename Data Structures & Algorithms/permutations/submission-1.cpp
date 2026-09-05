class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> _set;
        vector<int> state;
        dfs(_set, nums, state);
        return ans;
    }

    void dfs(unordered_set<int>& _set, vector<int>& nums, vector<int>& state){
        if(state.size()==nums.size()){
            ans.push_back(state);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!_set.count(i)){
                _set.insert(i);
                state.push_back(nums[i]);
                dfs(_set, nums, state);
                state.pop_back();
                _set.erase(i);
            }
        }
    }
};
