class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return dfs(0,0,m,n, dp);
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int x=0,y=0;
        if(i+1<m){
            x = dfs(i+1, j, m,n, dp);
        }
        if(j+1<n){
            y = dfs(i, j+1, m,n, dp);
        }
        dp[i][j]=x+y;
        return x+y;
    }
};
