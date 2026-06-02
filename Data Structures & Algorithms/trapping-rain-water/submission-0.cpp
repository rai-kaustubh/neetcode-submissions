class Solution {
public:
    int trap(vector<int>& nums) {
        //calc left _max vector
        vector<int> left(nums.size());
        int _max=nums[0];
        for(int i=0;i<nums.size();i++){
            auto temp = nums[i];
            left[i]=_max;
            _max = max(_max, nums[i]);
        }

        //calc right _max vector
        vector<int> right(nums.size());
        _max=nums.back();
        for(int i=nums.size()-1;i>0;i--){
            auto temp = nums[i];
            right[i]=_max;
            _max = max(_max, nums[i]);
        }

        
        auto sum=0;
        for(auto i=0;i<nums.size();i++){
            nums[i]=min(left[i], right[i])-nums[i];
            if(nums[i]>0){
                sum+=nums[i];
            }
        }

        return sum;


    }
};
