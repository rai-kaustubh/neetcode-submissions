struct pair_hash {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>{}(p.first) ^
               (hash<string>{}(p.second) << 1);
    }
};

class UndergroundSystem {
public:
    
    unordered_map<int, pair<int, string>> id_to_time; // in-time, station
    unordered_map<pair<string, string>, pair<long long, int>, pair_hash> stations_to_trip; //src, dest -> [total_times]

    UndergroundSystem() {
        id_to_time.clear();
        stations_to_trip.clear();
    }
    void checkIn(int id, string stationName, int t) {
        id_to_time[id]={t, stationName};
    }
    void checkOut(int id, string stationName, int t) {
        int beginTime = id_to_time[id].first;
        string src = id_to_time[id].second;
        
        if(stations_to_trip.count({src, stationName})){
            int totalTrips = stations_to_trip[{src, stationName}].second;
            long long totalTime = stations_to_trip[{src, stationName}].first;
            stations_to_trip[{src, stationName}]={totalTime + t-beginTime, ++totalTrips};
        } else {
            stations_to_trip[{src, stationName}]={t-beginTime, 1};
        }
        id_to_time.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int totalTrips = stations_to_trip[{startStation, endStation}].second;
        long long totalTime = stations_to_trip[{startStation, endStation}].first;

        return (double) totalTime/totalTrips;
    }
};
/*


*/
