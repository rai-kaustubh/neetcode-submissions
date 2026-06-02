class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int  _max=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            auto temp = nums[i];
            nums[i]=_max-nums[i];
            _max=max(temp, _max);
        }

        _max=0;
        for(int i=0;i<nums.size();i++){
            _max = max(_max, nums[i]);
        }

        return _max;

    }
};
