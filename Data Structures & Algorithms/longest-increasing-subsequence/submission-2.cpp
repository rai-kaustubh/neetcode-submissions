class Solution {
public:
    unordered_map<int, int> mp;
    int lengthOfLIS(vector<int>& nums) {
        int LIS = 1;
        for(int j=0;j<nums.size();j++){
            LIS = max(LIS, dfs(j, nums));
        }

        return LIS;
    }

    int dfs(int i, vector<int>& nums){
        if(i==nums.size()) return 0;
        if(mp.count(i)){
            return mp[i];
        }

        int LIS = 1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                LIS = max(LIS, 1+dfs(j, nums));
            }
        }
        mp[i] = LIS;
        return LIS;
    }
};
