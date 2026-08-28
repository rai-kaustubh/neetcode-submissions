class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto vec: times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;

        
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();

            auto d=vec.first;
            auto u=vec.second;

            if(d>dist[u]){
                continue;
            }

            for(auto nbor: adj[u]){
                auto v = nbor.first;
                auto w = nbor.second;
                if(d+w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v], v});
                }
            }
        }

        auto _max = *max_element(dist.begin()+1, dist.end());
        if(_max==INT_MAX){
            return -1;
        }

        return _max;
    }
};
