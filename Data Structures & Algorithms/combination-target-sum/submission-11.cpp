class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> state={};
        sort(nums.begin(), nums.end());
        helper(nums, target, state, 0);
        return ans;
    }

    void helper(vector<int>& nums, int target, vector<int>& state, int index){
        if(target<0) return;
        if(target==0){
            ans.push_back(state);
            return;
        }
        if(index == nums.size()){
            return;
        }
        if(nums[index]>target) return;

        state.push_back(nums[index]);
        helper(nums,target-nums[index], state, index);
        state.pop_back();
        helper(nums, target, state, index+1);
    }
};
/*
nums = [2,5,6,9]
target = 9


*/
