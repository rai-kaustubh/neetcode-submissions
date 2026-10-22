class Solution {
public:
    vector<vector<int>> ans={};
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            unordered_set<int> visited;
            visited.clear();
            visited.insert(i);

            vector<int> state;
            state.clear();
            state.push_back(nums[i]);

            helper(visited, state, nums);
        }

        return ans;
    }

    void helper(unordered_set<int>& visited, vector<int>& state, vector<int>& nums){
        if(state.size() == nums.size()){
            ans.push_back(state);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!visited.count(i)){
                state.push_back(nums[i]);
                visited.insert(i);
                helper(visited, state, nums);
                state.pop_back();
                visited.erase(i);
            }
        }

        return;
    }
};
/*
nums = [1,2,3]
i=0
i'=3
visited=0,1
state=1,2


*/
