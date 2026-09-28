class MinStack {
    vector<pair<int, int>> vec;
    int _min = INT_MAX;

   public:
    MinStack() {}

    void push(int val) {
        if (val < _min) {
            _min = val;
        }

        vec.push_back({val, _min});
    }

    void pop() {
        vec.pop_back();
        if(vec.size()>0)
            _min = vec.back().second;
        else
            _min = INT_MAX;
    }

    int top() { return vec.back().first; }

    int getMin() { return vec.back().second; }
};
/*
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1

min = INT_MAX;
1,1
2,1
0,0



*/