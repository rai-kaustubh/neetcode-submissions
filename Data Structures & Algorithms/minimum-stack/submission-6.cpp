class MinStack {
public:
    vector<pair<int, int>> vec;
    int min;
    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
       if(val<min){
        min=val;
       }
       vec.push_back({val, min}); 
    }
    
    void pop() {
        vec.erase(vec.end());
        
        min =vec.size()==0?INT_MAX:vec.back().second;
    }
    
    int top() {
        cout<< vec.back().first<<" ";
        return vec.back().first;
    }
    
    int getMin() {
        cout<< vec.back().second<<" ";
        return vec.back().second;
    }
};
