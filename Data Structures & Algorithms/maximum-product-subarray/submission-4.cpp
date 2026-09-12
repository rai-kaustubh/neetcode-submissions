class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int res = nums[0];
        
        for(int i=1;i<nums.size();i++){
            auto temp = maxProd;
            maxProd  = max(maxProd*nums[i], max(nums[i], minProd*nums[i]));
            minProd  = min(minProd*nums[i], min(nums[i], temp*nums[i]));
            res = max(maxProd, res);
        }

        return res;
    }
};
