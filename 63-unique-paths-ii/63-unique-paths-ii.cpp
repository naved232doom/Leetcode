class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = (int)(g.size());
        int m = (int)(g[0].size());
        if (g[n - 1][m - 1] || g[0][0]) return 0;
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j]) continue;
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};