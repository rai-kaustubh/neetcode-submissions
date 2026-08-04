class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> _map;

        for(int i=0;i<nums.size();i++){
            _map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            auto temp = _map.find(target-nums[i]);

            if(temp !=_map.end() && temp->second!=i){
                return {i, temp->second};
            }
        }

        return {0,0};
    }
};
