class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token:tokens){
            if(token!="+" && token!="-" && token!="/" && token!="*" ){
                st.push(stoi(token));
            } else if(token=="+"){
                int op2=st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1+op2);
            } else if(token=="/"){
                int op2=st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1/op2);
            } else if(token=="*"){
                int op2=st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1*op2);
            } else if(token=="-"){
                int op2=st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1-op2);
            }
        }

        return st.top();
    }
};
/*
    st - 9,4
*/
