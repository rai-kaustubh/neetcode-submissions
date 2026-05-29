class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(int i=0;i<strs.size();i++){
            vector<int> count(26,0);
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }
            string str="";
            for(int k=0;k<count.size();k++){
                str+=to_string(count[k])+"#";
            }

            res[str].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
