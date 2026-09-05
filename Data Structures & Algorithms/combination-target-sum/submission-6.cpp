class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> state;
        dfs(state, target, nums, 0);
        return ans;
    }

    void dfs(vector<int>& state, int left, vector<int>& nums, int j){
        if(left<0) return ;
        if(left ==0){
            ans.push_back(state);
            return ;
        }

        for(int i=j;i<nums.size();i++){
            state.push_back(nums[i]);
            left-=nums[i];
            dfs(state, left, nums, i);
            state.pop_back();
            left+=nums[i];
        }
    }
};
