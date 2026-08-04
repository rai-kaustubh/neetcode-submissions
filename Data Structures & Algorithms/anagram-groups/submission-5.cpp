class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> _map;

        for(auto s: strs){
            vector<int> vec(26,0);
            for(int i=0;i<s.length();i++){
                vec[s[i]-'a']++;
            }

            string result="";
            for (int num : vec) {
                result += std::to_string(num) + " ";
            }

            _map[result].push_back(s);
        } 

        vector<vector<string>> ans;
        for(auto i=_map.begin();i!=_map.end();i++){
            ans.push_back(i->second);
        }

        return ans;
    }
};
