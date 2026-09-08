class Solution {
public:
    unordered_set<string> mp = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26"
    };

    vector<int> dp;

    int dfs(int j, string& s) {
        if (j == s.size())
            return 1;

        if (dp[j] != -1)
            return dp[j];

        int ways = 0;

        for (int i = j; i < j + 2 && i < s.size(); i++) {
            string str = s.substr(j, i - j + 1);

            if (mp.count(str)) {
                ways += dfs(i + 1, s);
            }
        }

        return dp[j] = ways;
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        return dfs(0, s);
    }
};