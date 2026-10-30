class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> state={};
        helper(nums, 0, state);
        return ans;
    }

    void helper(vector<int>& nums, int index, vector<int>& state){
        if(index==nums.size()){
            ans.push_back(state);
            return;
        }

        state.push_back(nums[index]);
        helper(nums, index+1, state);
        state.pop_back();
        helper(nums, index+1, state);

    }
};
/*

*/
