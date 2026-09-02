class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> _map;
        for(auto h: hand){
            _map[h]++;
        }

        while(!_map.empty()){
            int count=1;
            int prev = _map.begin()->first;
            _map[prev]--;
            if(_map[prev]==0){
                _map.erase(prev);
            }
            while(count<groupSize){
                if(_map.count(prev+1)){
                    _map[prev+1]--;
                    count++;
                    
                    if(_map[prev+1]==0){
                        _map.erase(prev+1);
                    }
                    prev++;
                } else{
                    return false;
                }
            }
        }

        return true;
    }
};
