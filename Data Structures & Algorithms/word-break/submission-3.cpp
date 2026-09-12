class Solution {
public:
    unordered_map<int, bool> mp; 
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return dfs(0, st, s);// if s can be segmented from index i;
    }

    bool dfs(int i, unordered_set<string>& st, string& s){
        if(i==s.size()) return true;
        if(mp.count(i)) return mp[i];

        int ans =false;
        for(int j=i;j<s.size();j++){
            string str = s.substr(i, j-i+1);
            if(st.count(str)){
                ans = ans|| dfs(j+1, st, s);
            }
        }

        return mp[i]=ans;

    }
};
