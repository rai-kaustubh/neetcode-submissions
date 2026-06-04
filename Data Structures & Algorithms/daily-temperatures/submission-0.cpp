class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> result(nums.size());
        stack<pair<int,int>> _stack;

        for(int i=0;i<nums.size();i++){
            if(_stack.empty()){
                _stack.push({nums[i], i});
            } else {
                while(!_stack.empty() && nums[i]>_stack.top().first){
                    result[_stack.top().second]=i-_stack.top().second;
                    _stack.pop();
                }

                _stack.push({nums[i], i});
            }
        }

        while(!_stack.empty()){
            result[_stack.top().second]=0;
            _stack.pop();
        }

        return result;
    }
};
