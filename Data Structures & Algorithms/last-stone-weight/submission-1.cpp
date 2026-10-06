class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        // pq.clear();

        for(auto stone:stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();

            pq.push(top-top2);
        }

        return pq.top();
    }

};
/*

*/