class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = (int)(g[0].size());
        const int inf = 1e9;
        vector<vector<int>> dp(n, vector<int>(m, inf));
        dp[0][0] = g[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i - 1 >= 0)
                    dp[i][j] = min(dp[i - 1][j] + g[i][j], dp[i][j]);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j - 1] + g[i][j], dp[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};