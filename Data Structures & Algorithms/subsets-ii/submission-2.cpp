class Solution {
public:
    vector<vector<int>> ans;
    // ans.clear();
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> state;
        helper(state, nums, 0);
        return ans;    
    }

    void helper(vector<int>& state, vector<int>& nums, int index){
        if(index==nums.size()){
            ans.push_back(state);
            return;
        }
        
        state.push_back(nums[index]); //choose to add nums[index] in subset and explore
        helper(state, nums, index+1);
        state.pop_back();
        
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        helper(state, nums, index+1); // explore paths where nums[index] in not in subset
    }
};

/*
nums = [1,1,2]
state=
index=0->n-1

*/
