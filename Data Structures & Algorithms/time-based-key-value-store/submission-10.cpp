class TimeMap {
unordered_map<string, vector<pair<int, string>>> kv;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!kv.count(key)) return "";
        if(kv[key][0].first > timestamp) return "";
        if(kv[key].back().first<=timestamp) return kv[key].back().second;

        int l=0, r=kv[key].size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(kv[key][mid].first == timestamp || kv[key][mid].first<timestamp &&kv[key][mid+1].first>timestamp){
                return kv[key][mid].second;
            }

            if(kv[key][mid].first<timestamp){
                l=mid+1;
            } else{
                r=mid-1;
            }
        }

        return "";
        
    }
};
/*
Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
timeMap.get("alice", 1);           // return "happy"
timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
timeMap.get("alice", 3);           // return "sad"

map<int, vector<pair<int, val>>

alice-> [happy, 1], [sad,3]
if(map[key].back().first<=timestamp) return map[key].back().second;
if(map[key][0].first > timestamp) return "";

else{
    l = 0,
    
}

*/
