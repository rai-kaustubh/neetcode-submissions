class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> _stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"
                && tokens[i]!="-"
                && tokens[i]!="*"
                && tokens[i]!="/") {
                    _stack.push(stoi(tokens[i]));
            } else{
                auto op1 = _stack.top();
                _stack.pop();
                auto op2 = _stack.top();
                _stack.pop();
            

                if (tokens[i] == "*"){
                    _stack.push(op2*op1);
                } else if (tokens[i]=="/"){
                    _stack.push(op2/op1);
                } else if (tokens[i]=="-"){
                    _stack.push(op2-op1);
                } else{
                    _stack.push(op1+op2);
                } 
                
            }
        }

        return _stack.top();
    }
};
