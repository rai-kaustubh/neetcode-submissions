class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> _map;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        _map[key].push_back({timestamp, value});
    }

    string get(string k, int t) {
        if(_map.find(k)==_map.end()){
            return "";
        }
        vector<pair<int, string>> vec = _map[k];

        int l=0, r=vec.size()-1;

        if(vec.back().first <= t){ // t > max timestamp
            return vec.back().second; 
        }
        if(vec[0].first >t){
            return "";
        }

        while(l<=r){
            int mid = l+(r-l)/2;

            if(vec[mid].first == t || vec[mid].first<t &&vec[mid+1].first>t){
                cout<<vec[mid].second<<" ";
                return vec[mid].second;
            }


            if(vec[mid].first > t){
                r = mid-1;
            } else{
                l=mid+1;
            }
        }

        return "";
    }
};
