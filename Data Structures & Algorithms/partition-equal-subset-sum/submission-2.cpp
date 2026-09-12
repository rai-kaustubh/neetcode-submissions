class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2!=0) return false;
        return dfs(sum/2, 0, nums);

    }

    bool dfs(int target, int i, vector<int>& nums) {
        if(i>=nums.size()){
            return target==0;
        }
        if(target<0) return false;
        
        return dfs(target-nums[i], i+1, nums) || dfs(target, i+1, nums);
    }
    
};
