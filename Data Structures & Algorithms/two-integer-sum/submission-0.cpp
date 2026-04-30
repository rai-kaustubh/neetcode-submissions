class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // target =8
        // 4-1
        // 5-2
        // 6-3

        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            auto temp = map.find(target-nums[i]);
            if(temp!=map.end() && temp->second !=i)
                return {i,temp->second};
        }

        return {};

    }
};
