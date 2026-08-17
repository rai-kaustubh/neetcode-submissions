class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
                continue;
            } else if(st.empty() ||
                        c==']' && !st.empty() && st.top()!='['
                      || c=='}' && !st.empty() && st.top()!='{'
                      || c==')' && !st.empty() && st.top()!='(')
                      return false;
            else st.pop();
        }

        return st.empty();
    }
};
