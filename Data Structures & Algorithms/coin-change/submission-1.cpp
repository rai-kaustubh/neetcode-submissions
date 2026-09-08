class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
    
    int dfs(int amount, vector<int>& coins){
        if(amount==0){
            return 0;
        }

        if(memo.count(amount)){
            return memo[amount];
        }

        int res = INT_MAX;
        for(auto coin: coins){
            if(amount-coin>=0){
                auto result =  dfs(amount-coin, coins);
                if(result!=INT_MAX){
                    res = min(1+result, res);
                }
            }
        }

        memo[amount] = res;
        return res;




    }
};
