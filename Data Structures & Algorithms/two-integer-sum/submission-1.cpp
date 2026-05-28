class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //    3-0
    //    4-1
    //    5-2
    //    6-3

    //    if(target-_map[i] is there in map){
    //     return {map[i], map[target-i]}
    //    } 

        unordered_map<int, int> map;
        for(int i=0; i<nums.size();i++){
            map[nums[i]]=i;
        }
        
        for(auto i=0;i!=nums.size();i++){
            auto temp = map.find(target-nums[i]);
            if(temp!=map.end() && temp->second != i){
                return { i, temp->second,};
            }
        }

        return {0,0};
    }
};
