class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sett(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        memo[s.size()]=true;
        return dfs(s, sett, 0, memo);
    }
    
    bool dfs(string&s, unordered_set<string>& wordDict, int i, unordered_map<int, bool>& memo){
        if(i==s.size()) return true;
        
        if(memo.count(i)){
            return memo[i];
        }
        
        // res = false;
        for(int j=i;j<s.size();j++){
            if(wordDict.count(s.substr(i,j-i+1))){
                if(dfs(s, wordDict, j+1, memo)){
                    memo[i]=true;
                    return true;
                }
            }
        }

        memo[i]=false;
        return false;
    }
};
