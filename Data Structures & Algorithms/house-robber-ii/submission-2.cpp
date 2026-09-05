class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums.back();
        if(nums.size()==2) return *max_element(nums.begin(), nums.end());
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(robHelper(v1), robHelper(v2));
    }

    int robHelper(vector<int> vec){
        vector<int> dp(vec.size());
        dp[0] = vec[0];
        dp[1] = max(vec[0],vec[1]);

        for(int i=2;i<dp.size();i++){
            dp[i] = max(vec[i]+dp[i-2], dp[i-1]);
        }

        return dp.back();
    }
};
