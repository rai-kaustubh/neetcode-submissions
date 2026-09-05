class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> state;
        dfs(state, nums,0);
        return ans;
    }

    void dfs(vector<int>& state, vector<int>& nums, int j){
        ans.push_back(state);

        for(int i=j;i<nums.size();i++){
            state.push_back(nums[i]);
            dfs(state, nums, i+1);
            state.pop_back();
        }
    }

};
