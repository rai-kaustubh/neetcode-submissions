class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        
        memo.resize(nums.size(), vector<int> (nums.size(), -1));
        return dfs(0, -1, nums);
    }
    int dfs(int i, int j, vector<int>& nums){
        if(i==nums.size()){
            return 0;
        }
        if(memo[i][j+1]!=-1){
            return memo[i][j+1];
        }

        int ans;
        if(j==-1 || nums[j]<nums[i]){
            ans =  1+dfs(i+1, i, nums);
        }

        return memo[i][j+1]=max(dfs(i+1,j, nums), ans);
    }
};
