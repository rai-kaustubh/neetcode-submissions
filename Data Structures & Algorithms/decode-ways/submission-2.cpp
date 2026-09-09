class Solution {
public:
    unordered_set<string> mp = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26"
    };

    unordered_map<int, int> memo;

    int numDecodings(string s) {
        
        return dfs(s, 0);
    }

    int dfs(string& s, int i){
        if(i==s.size()){
            return 1;
        }

        if(memo.count(i)){
            return memo[i];
        }

        auto res = 0;
        for(int j=i;j<s.size() && j<i+3;j++){
            auto str = s.substr(i, j-i+1);
            if(mp.count(str)){
                res+=dfs(s, j+1);
            }
        }
        memo[i] = res;
        return res;
    }
};