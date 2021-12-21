class Solution {
private:
    int dy1[9] = { -1, 1, 0,-1, 1, 0,-1, 1, 0};
    int dy2[9] = {0,0,0,1,1,1,-1,-1,-1};
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = (int)(grid.size()), m = (int)(grid[0].size());
        int dp[n + 1][m + 1][m + 1];
        memset(dp, 0, sizeof dp);
        int ans=0;
        for (int r = n - 1; r >= 0; --r) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i != j) {
                        dp[r][i][j] = (grid[r][i] + grid[r][j]);
                    }
                    else {
                        dp[r][i][j] = grid[r][i];
                    }
                    if (r == n - 1) continue;
                    int initial = dp[r][i][j];
                    for (int x = 0; x <9; ++x) {
                        int nx = r + 1, ny1 = i + dy1[x], ny2 = j + dy2[x];
                if (nx >= 0 && nx < n && ny1 >= 0 && ny1 < m && ny2 >= 0 && ny2 < m) {
                            if (ny1 == ny2) {
                                    // dp[nx][y][y]
                                int now = dp[nx][ny1][ny2];
                                dp[r][i][j] = max(dp[r][i][j], initial + now);
                            }
                        else{
                                int now=dp[nx][ny1][ny2];
                                dp[r][i][j]=max(dp[r][i][j],initial+now);
                        }
                        ans=max(ans,dp[r][i][j]);
                        }
                    }
                }
            }
        }
          return dp[0][0][m-1];
    }
};