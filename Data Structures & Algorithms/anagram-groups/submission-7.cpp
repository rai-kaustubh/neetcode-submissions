class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> kv;
        vector<vector<string>> ans={};
        
        for(auto s : strs){
            vector<int> key(26,0);
            for(char c: s){
                key[c-'a']++;
            }

            string k="";
            for(int i=0;i<26;i++){
                k+=to_string(key[i])+",";
            }

            kv[k].push_back(s);
        }

        for(auto i=kv.begin();i!=kv.end();i++){
            ans.push_back(i->second);
        }

        return ans;
    }
};
/*
    
*/
