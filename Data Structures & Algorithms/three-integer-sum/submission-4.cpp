class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;

            int l=i+1;
            int r=nums.size()-1;
            int target = 0-nums[i];
            while(l<r){
                if(nums[l]+nums[r]==target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    // break;
                    
                    l++;
                    while(l<nums.size() && nums[l]==nums[l-1]) l++;
                    // r--;÷
                    continue;
                }

                if(nums[l]+nums[r]>target){
                    r--;
                } else{
                    l++;
                }
            }
        }

        return res;
    }
};
