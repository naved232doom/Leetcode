class Solution {
public:
    typedef long long ll;
    bool valid(int X, int Y, int n, int m) {
        return X >= 0 && Y >= 0 && X < n && Y < m;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        ll dp[maxMove + 2][n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        
        long long int ans = 0;
        const int mod = (int)(1e9 + 7);
        dp[0][startRow][startColumn] = 1;
        vector<int> dx = { -1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        // 50 * 50 * 50 *4
        // 6*1e5
        for (int moves = 0; moves < maxMove; ++moves) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        int d_x = dx[d] + i;
                        int d_y = dy[d] + j;
                        if (valid(d_x, d_y, n, m)) {
                            dp[moves + 1][i][j] += dp[moves][d_x][d_y];
                            dp[moves + 1][i][j] %= mod;
                        }
                    }
                }
            }
        }
        
        for (int moves = 0; moves < maxMove; ++moves) {
        int vis[n][m];
        memset(vis,0,sizeof vis);
            for (int i = 0; i < m; ++i) {
                int cnt_corners = 0;
                int x = 0, y = i;
                if(vis[x][y]) continue;
                for (int d = 0; d < 4; ++d) {
                    int X = x + dx[d], Y = y + dy[d];
                    if (!valid(X, Y, n, m)) cnt_corners++;
                }
                ans += (dp[moves][0][i] * cnt_corners) % mod;
                ans%=mod;
                vis[x][y]=1;
                cnt_corners = 0;
                x = n - 1, y = i;
                if(vis[x][y]) continue;
                for (int d = 0; d < 4; ++d) {
                    int X = x + dx[d], Y = y + dy[d];
                    if (!valid(X, Y, n, m)) cnt_corners++;
                }
                ans += (dp[moves][n - 1][i] * cnt_corners) % mod;
                ans%=mod;
                vis[x][y]=1;

            }
            for (int i = 1; i < n - 1; ++i) {
                int cnt_corners = 0;
                int x = i, y = 0;
                if(vis[x][y]) continue;
                for (int d = 0; d < 4; ++d) {
                    int X = x + dx[d], Y = y + dy[d];
                    if (!valid(X, Y, n, m)) cnt_corners++;
                }
                ans += (dp[moves][i][0] * cnt_corners) % mod;
                ans%=mod;
                vis[x][y]=1;
                cnt_corners = 0;
                x = i, y = m - 1;
                if(vis[x][y]) continue;
                for (int d = 0; d < 4; ++d) {
                    int X = x + dx[d], Y = y + dy[d];
                    if (!valid(X, Y, n, m)) cnt_corners++;
                }
                vis[x][y]=1;
                ans += (dp[moves][x][y] * cnt_corners) % mod;
                ans%=mod;

            }
        }
        return ans;
    }
};