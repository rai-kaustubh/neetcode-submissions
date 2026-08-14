class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> state;
        sort(nums.begin(), nums.end());
        dfs(nums, target, state, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int target, vector<int>& state, int sum, int i){
        if(sum==target){
            ans.push_back(state);
            return;
        }
        if(i>=nums.size()) return;

        for(int j=i;j<nums.size();j++){
            if(j>i and nums[j]==nums[j-1]){
                continue;
            }
            if(sum+nums[j]>target) return;
            state.push_back(nums[j]);
            dfs(nums, target, state, sum+nums[j], j+1);
            state.pop_back();
        }
    }
};
