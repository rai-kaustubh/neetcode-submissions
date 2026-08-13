class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(auto x: stones){
            pq.push(x);
        }

        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x-y>0) pq.push(x-y);
            continue;
        }

        if(pq.size()){
            return pq.top();
        }
        return 0;
    }
};
