class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> _map;

        for (char c : s) {
            _map[c]++;
        }

        int i = 0;
        unordered_set<char> _set;
        vector<int> res;

        while (i < s.size()) {
            int count = 0;

            while (i < s.size()) {
                char c = s[i];

                _set.insert(c);

                _map[c]--;

                if (_map[c] == 0) {
                    _map.erase(c);
                    _set.erase(c);
                }

                i++;
                count++;

                // Partition is complete
                if (_set.empty()) {
                    break;
                }
            }

            res.push_back(count);
        }

        return res;
    }
};