class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            int tmp = currMax * nums[i];
            currMax = max(max(currMax*nums[i], currMin*nums[i]), nums[i]);
            currMin = min(min(tmp, currMin*nums[i]), nums[i]);
            res = max(currMax, res);
        }

        return res;
    }
};
