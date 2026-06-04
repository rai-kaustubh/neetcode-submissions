class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> _stack;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i].compare("+") == 0){
                int op1 = _stack.top();
                _stack.pop();

                int op2 = _stack.top();
                _stack.pop();

                _stack.push(op2+op1);
            } else if(tokens[i].compare("-") == 0){
                int op1 = _stack.top();
                _stack.pop();

                int op2 = _stack.top();
                _stack.pop();

                _stack.push(op2-op1);
            } else if(tokens[i].compare("/") == 0){
                int op1 = _stack.top();
                _stack.pop();

                int op2 = _stack.top();
                _stack.pop();

                _stack.push(op2/op1);
            } else if(tokens[i].compare("*") == 0){
                int op1 = _stack.top();
                _stack.pop();

                int op2 = _stack.top();
                _stack.pop();

                _stack.push(op2*op1);
            } else{
                _stack.push(stoi(tokens[i]));
            }
        }

        return _stack.top();
    }
};