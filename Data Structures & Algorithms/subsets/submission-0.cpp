class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;

       helper(ans, nums, {}, 0); 
       return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> state, int i){
        if(i>=nums.size()){
            ans.push_back(state);
            return;
        } 
        
        helper(ans, nums, state, i+1);
        state.push_back(nums[i]);
        helper(ans, nums, state, i+1);
    }
};
