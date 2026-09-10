class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==0){
            memo.resize(nums.size(), vector<int> ((sum/2)+1, -1));
            return dfs(0, nums, sum/2);
        }
        return false;
    }

    bool dfs(int i, vector<int>& nums, int sum){
        if(sum==0) return true;
        if(sum<0 || i==nums.size()) return false;

        if(memo[i][sum]!=-1){
            return memo[i][sum];
        }
         
        memo[i][sum] = dfs(i+1, nums, sum) || dfs(i+1, nums, sum-nums[i]); 
        return memo[i][sum];
    }
};
