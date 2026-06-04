class Solution {
public:
    bool isValid(string a) {
        stack<char> _stack;

        for(int i=0;i<a.length();i++){
            if(a[i]=='{' || a[i]=='(' || a[i]=='['){
                _stack.push(a[i]);
            } else{
                if(_stack.empty() 
                    || a[i] == '}' && _stack.top()!='{'
                    || a[i] == ')' && _stack.top()!='('
                    || a[i] == ']' && _stack.top()!='['
                ) {
                    return false;
                } else{
                    _stack.pop();
                }
            }
        }
        if(_stack.empty())
        return true;

        return false;
    }
};
