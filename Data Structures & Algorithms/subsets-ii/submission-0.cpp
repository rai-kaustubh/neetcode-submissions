class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> state;
        sort(nums.begin(), nums.end());
        dfs(nums, state, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& state, int index){
        if(index>nums.size()) return;
        res.push_back(state);

        for(int i=index; i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;

            state.push_back(nums[i]);
            dfs(nums, state, i+1);
            state.pop_back();
        }
    }
};
