class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
        
            iniliatise dist vect to inf for all vertices
            set source dist to 0, add it to q;
            while (!q.empty()){
                u,d = q.top();
                q.pop();

                if(dist[u]< d) continue; // repeated edge calc

                for(v,w: adj[u]){
                    
                    if(d+w<dist[v]){
                        dist[v] = d+w;
                        q.push({v, dist[v]})
                    }
                }
            }

            max_ele = max_element(dist.begin()+1, dist.end());
            return (max_elem == INT_MAX)?-1:max_ele;
        
        */

        // build adj list;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time: times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q;
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        q.push({k,0});

        while(!q.empty()){
            auto u = q.top().first;
            auto d = q.top().second;
            q.pop();

            if(d>dist[u]) 
                continue;

            for(auto p: adj[u]){
                auto v = p.first;
                auto w = p.second;

                if(dist[v] > w+d){
                    dist[v]=w+d;
                    q.push({v, w+d});
                }
            }
        }

        auto max_ele = *max_element(dist.begin()+1, dist.end());
        return (max_ele == INT_MAX)?-1:max_ele;


    }
};
