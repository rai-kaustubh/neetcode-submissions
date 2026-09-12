class Solution {
public:
    unordered_map<int, int> memo;
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return *max_element(nums.begin(), nums.end());
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        auto resultV1 = dfs(v1.size()-1, v1);
        memo.clear();
        auto resultV2 = dfs(v2.size()-1, v2);

        return max(resultV1, resultV2);
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
