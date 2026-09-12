class Solution {
   public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2!=0) return false;
        memo.resize((sum/2)+1, vector<int>(nums.size(),-1));
        return dfs(sum/2, 0, nums);

    }

    bool dfs(int target, int i, vector<int>& nums) {
        if(i>=nums.size()){
            return target==0;
        }
        if(target<0) return false;

        if(memo[target][i]!=-1) return memo[target][i];
        
        return memo[target][i] = dfs(target-nums[i], i+1, nums) || dfs(target, i+1, nums);
    }
    
};
