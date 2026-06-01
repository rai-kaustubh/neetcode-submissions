class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int  _max=nums[nums.size()-1];
        vector<int> maxVector(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            maxVector[i]=max(nums[i], _max);
            _max=max(nums[i], _max);
        }

        _max=0;
        for(int i=0;i<nums.size();i++){
            _max = max(_max, maxVector[i]-nums[i]);
        }

        return _max;

    }
};
