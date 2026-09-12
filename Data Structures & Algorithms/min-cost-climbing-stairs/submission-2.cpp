class Solution {
public:
    unordered_map<int, int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        return dfs(cost.size(), cost);
    }

    int dfs(int i, vector<int>& cost){
        if(i==0||i==1){
            return 0;
        }

        if(memo.count(i)) return memo[i];

        return memo[i] = min(dfs(i-1, cost)+cost[i-1], dfs(i-2, cost)+cost[i-2]);
    }
    
};
