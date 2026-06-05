class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        // -2,-1,1, 2
        // stack = -2,-1 
        stack<int> _stack;

        for(auto num:nums){
            if(_stack.empty()){
                _stack.push(num);
                continue;
            } 

            auto top =_stack.top();
            auto flag=false;
            
            if(top*num>0 || (top*num<0 && top<0)) {
                _stack.push(num);
                continue;
            }

            while(top>0 && num<0){ 
                if(abs(top) < abs(num)){ // curr is bigger
                    _stack.pop();
                    flag=true;
                } else if(abs(top)==abs(num)){ // both are equal
                    _stack.pop();
                    flag=false;

                    break;
                } else { // top is bigger
                    flag=false;

                    break;
                }

                if(_stack.empty()){
                    break;
                } else {
                    top =_stack.top();
                }
            }

            if(flag){
                _stack.push(num);
            }
        }

        vector<int> result;
        while(!_stack.empty()){
            result.push_back(_stack.top());
            _stack.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};