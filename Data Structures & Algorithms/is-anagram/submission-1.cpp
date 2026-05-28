class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> _map;

        for(int i=0;i<s.length();i++){
            _map[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            _map[t[i]]--;
        }

        for(auto i=_map.begin();i!=_map.end();i++){
            if(i->second != 0){
                return false;
            }
        }

        return true;

    }
};
