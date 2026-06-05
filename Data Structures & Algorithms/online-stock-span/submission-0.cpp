class StockSpanner {
   public:
    // 100 - 1,80 - 1,60 - 1,70-(2),60,75-(4),85-6

    // s1 = 100,80,60
    // s2 = 7
    stack<int> s1;
    stack<int> s2;
    StockSpanner() {}

    int next(int price) {
        auto _count = 0;
        if (s1.empty()|| s1.top()>price) {
            s1.push(price);
            return 1;
        } else {
            while (!s1.empty() && s1.top() <= price) {
                s2.push(s1.top());
                s1.pop();
                _count++;
            }
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
                // _count++;
            }
            s1.push(price);
        }

        return _count+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */