class StockSpanner {
public:
    // [[], [100,1], [80,1], [75,4], [85]]
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty() || s.top().first > price){
            s.push({price,1});
            return 1;
        }

        int res=0;
        while(!s.empty() && s.top().first<=price){
            res+=s.top().second;
            s.pop();
        }

        s.push({price, res+1});
        return res+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */