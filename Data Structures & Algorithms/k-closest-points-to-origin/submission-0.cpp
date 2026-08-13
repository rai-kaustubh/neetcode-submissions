struct Compare {
    bool operator()(const pair<double, vector<int>>& a,
                    const pair<double, vector<int>>& b) {
        return a.first < b.first;  // min-heap based only on first
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, Compare> pq;

        for(auto p: points){
            auto dist = sqrt(p[0]*p[0] + p[1]*p[1]);
            pq.push({dist, p});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
