class Solution {
public:
    unordered_map<int, int> memo;
    int rob(vector<int>& nums) {
        return dfs(nums.size()-1, nums) ;// max money i can rob till ith house
    }
    
    int dfs(int i, vector<int>& nums){
        if(i==0){
            return nums[0];
        }        
        if(i==1){
            return max(nums[0], nums[1]);
        }
        if(memo.count(i)) return memo[i];
        return memo[i] = max(nums[i]+ dfs(i-2, nums), dfs(i-1, nums));
    }
};
