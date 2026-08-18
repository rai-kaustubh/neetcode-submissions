class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=2){
            return *max_element(nums.begin(), nums.end());
        }
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[1], nums[0]);
        // dp[2]=max(nums[0],max(nums[2],nums[0]+nums[2]));

        for(int i=2;i<nums.size();i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp.back();
    }
};
