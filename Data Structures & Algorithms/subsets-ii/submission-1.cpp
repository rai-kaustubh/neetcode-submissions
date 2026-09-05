class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> state;
        dfs(state, 0, nums);
        return ans;
    }

    void dfs(vector<int>& state, int j, vector<int>& nums){
        ans.push_back(state);

        for(int i=j;i<nums.size();i++){
            if(i!=j && nums[i]==nums[i-1]) continue;

            state.push_back(nums[i]);
            dfs(state, i+1, nums);
            state.pop_back();
        }
    }
};
