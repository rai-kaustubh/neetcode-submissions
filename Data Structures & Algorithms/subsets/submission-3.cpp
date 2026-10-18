class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> state={};
        backtrack(nums, 0, state);
        return ans;
    }

    void backtrack(vector<int>& nums, int index, vector<int>& state){
        if(index==nums.size()){
            ans.push_back(state);
            return;
        }

        state.push_back(nums[index]);
        backtrack(nums, index+1, state);
        state.pop_back();
        backtrack(nums, index+1, state);
    }
};
/*
    Input: nums = [1,2,3]
    index=0

    ans = {1,2,3}, {}, {2,3}, 

*/
