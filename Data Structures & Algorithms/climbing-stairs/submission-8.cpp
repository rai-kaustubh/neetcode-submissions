class Solution {
public:
    unordered_map<int, int> memo;
    int climbStairs(int n) {
        // memo.resize(n+1, -1);
        return dfs(n);
    }

    int dfs(int n){
        if(n==1){
            return 1;
        }
        if(n==2) return 2;

        if(memo.count(n)){
            return memo[n];
        }

        return memo[n]=dfs(n-1) + dfs(n-2);
    }
};
