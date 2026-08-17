class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s: tokens){
            if(s=="*"){
                auto op1 = stoi(st.top());
                st.pop();
                auto op2 = stoi(st.top());
                st.pop();

                st.push(to_string(op1*op2));
            } else if(s=="+"){
                auto op1 = stoi(st.top());
                st.pop();
                auto op2 = stoi(st.top());
                st.pop();

                st.push(to_string(op1+op2));
            } else if(s=="-"){
                auto op1 = stoi(st.top());
                st.pop();
                auto op2 = stoi(st.top());
                st.pop();

                st.push(to_string(op2-op1));
            } else if(s=="/"){
                auto op1 = stoi(st.top());
                st.pop();
                auto op2 = stoi(st.top());
                st.pop();

                st.push(to_string(op2/op1));
            } else{
                st.push(s);
            }

        }

        return stoi(st.top());
    }
};
