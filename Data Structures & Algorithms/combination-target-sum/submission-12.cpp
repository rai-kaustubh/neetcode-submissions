class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> state={};
        helper(target, state, nums, 0);
        return ans;
    }

    void helper(int target, vector<int>& state, vector<int>& nums, int index){
        if(target<=0 || index == nums.size()){
            if(target==0){
                ans.push_back(state);
            }

            return;
        }

        state.push_back(nums[index]);
        helper(target-nums[index], state, nums, index);
        state.pop_back();
        helper(target, state, nums, index+1);
    }
};
/*
    target, state, nums, index

    state.push_back(nums[index]);
    helper(target-nums[index], state, nums, index);
    state.pop_back();
    helper(target-nums[index], state, nums, index+1);
*/
