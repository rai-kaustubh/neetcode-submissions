class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> _map;
        for(int x: nums){
            if(_map.find(x)!=_map.end()){
                return true;
            }

            _map[x]++;
        }

        return false;
    }
};