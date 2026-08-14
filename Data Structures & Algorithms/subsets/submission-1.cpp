class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
       dfs(nums, {}, 0); 
       return ans;
    }

    void dfs(vector<int>& nums, vector<int> subset, int i){
        if(i>=nums.size()) {

        ans.push_back(subset);
            return;
        }
        //push current subset in ans;

        // 2 options
        // choose to include current elemetn into set
        // add it to subset, do dfs in (i+1)
        subset.push_back(nums[i]);
        dfs(nums, subset, i+1);
        // choose not to include curr elemtn in set
        subset.pop_back();
        dfs(nums, subset, i+1);

    }

};
