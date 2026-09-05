class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> state;
        int j=0;
        sort(candidates.begin(), candidates.end());
        dfs(state, target, j, candidates);
        return ans;
    }

    void dfs(vector<int>& state, int& left, int j, vector<int>& nums){
        if(left<0) return;
        if(left ==0){
            ans.push_back(state);
            return;
        }

        for(int i=j;i<nums.size();i++){
            if(i!=j && nums[i] == nums[i-1]) continue;
            if(left-nums[i]<0) break;
            state.push_back(nums[i]);
            left-=nums[i];
            dfs(state, left, i+1, nums);
            state.pop_back();
            left+=nums[i];
        }
    }
};
