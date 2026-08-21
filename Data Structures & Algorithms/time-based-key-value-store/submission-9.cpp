class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }   
    
    string get(string key, int timestamp) {
        if(timemap.find(key)==timemap.end()) return "";

        if(timestamp >=this->timemap[key].back().second){
            return timemap[key].back().first;
        }
        if(timestamp < this->timemap[key][0].second){
            return "";
        }

        int l=0,r=timemap[key].size()-1;
        int mid;
        while(l<=r){
            mid =l+(r-l)/2;
            if(timestamp ==timemap[key][mid].second ||  timestamp >timemap[key][mid].second && timestamp< timemap[key][mid+1].second){
                return timemap[key][mid].first;
            }

            if(timestamp > timemap[key][mid].second){
                l=mid+1;
            } else r=mid-1;
        }

        return "";
    }
};
