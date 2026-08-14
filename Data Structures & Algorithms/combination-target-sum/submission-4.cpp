class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        helper(nums, target, cur, 0, 0);
        return ans;
    }

    void helper(vector<int>& nums, int target, vector<int>& state, int sum, int i){
        if(sum==target){
            ans.push_back(state);
            return;
        }
        
        if(i>=nums.size() || sum>target) return ;

        //include nums[i] in the sum, explore I
        state.push_back(nums[i]);
        helper(nums, target, state, sum+nums[i], i);
        // backtrack and not include i+1 in the the sum, explore i+1
        state.pop_back();
        helper(nums, target, state, sum, i+1);

    }
};
