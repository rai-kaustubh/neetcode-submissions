class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> _map;

        // Count remaining occurrences of every character
        for (char c : s) {
            _map[c]++;
        }

        unordered_set<char> _set;
        vector<int> res;

        int i = 0;

        while (i < s.size()) {
            int count = 0;

            while (i < s.size()) {
                char c = s[i];

                // Character is part of current partition
                _set.insert(c);

                // One occurrence has been processed
                _map[c]--;

                // No more occurrences of c remain
                if (_map[c] == 0) {
                    _map.erase(c);
                    _set.erase(c);
                }

                i++;
                count++;

                // All characters in current partition are finished
                if (_set.empty()) {
                    break;
                }
            }

            res.push_back(count);
        }

        return res;
    }
};