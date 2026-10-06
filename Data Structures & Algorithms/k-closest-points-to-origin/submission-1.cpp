class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>, vector<vector<double>>> pq;
        
        for(auto point: points){
            auto dist = sqrt(pow((point[0]-0), 2) + pow((point[1]-0), 2));
            pq.push({dist, (double)point[0],(double) point[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto point = pq.top();
            ans.push_back({(int)point[1],(int) point[2]});
            pq.pop();
        }

        return ans;
    }
};
/*

*/
