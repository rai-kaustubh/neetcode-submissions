class MinStack {
public:
    int min;
    stack<pair<int, int>>st; // number, min

    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(val<min){
            min =val;
        }
        cout<<val<<" "<<min<<endl;
        st.push({val,min});
    }
    
    void pop() {
        st.pop();
        if(st.empty()) min=INT_MAX;else
        min=st.top().second;
        cout<<min;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
