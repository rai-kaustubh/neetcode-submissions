class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> state={};
        helper(nums, target, 0, state);
        return ans;
    }

    void helper(vector<int>& nums, int target, int index, vector<int>& state){
        if(target==0){
            ans.push_back(state);
            return;
        }

        if(target<0 || index==nums.size() || nums[index]>target){
            return;
        }

        state.push_back(nums[index]);
        helper(nums, target-nums[index], index+1, state);
        state.pop_back();
        while(index<nums.size()-1 && nums[index]==nums[index+1]){
            index++;
        }
        helper(nums, target, index+1, state);
    }
};


/*
candidates = [9,2,2,4,6,1,5], target = 8
index -> include/not include
target==0 : valid state, add to ans and return 


*/
