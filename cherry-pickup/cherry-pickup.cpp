class Solution {
private:
    bool sameLocation(int x, int y, int X, int Y) {
        return x == X && y == Y;
    }
    bool valid(int x1, int y1, int x2, int y2, int n, int m) {
        return x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = (int)(grid.size()), m = (int)(grid[0].size());
        if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1) return 0;
        int dp[n + 1][m + 1][n + 1][m + 1];
        memset(dp, -1, sizeof dp);
        vector<int> dx1 = { -1, -1, 0, 0};
        vector<int> dy1 = {0, 0, -1, -1};
        vector<int> dx2 = { -1, 0, -1, 0};
        vector<int> dy2 = {0, -1, 0, -1};
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; --j) {
                for (int k = m - 1; k >= 0 ; --k) {
                    for (int l = m - 1; l >= 0; --l) {
                        if (grid[i][k] == -1 || grid[j][l] == -1) continue;
                            if(dp[i][k][j][l]==-1){
                                    if(i==n-1&&j==n-1&&l==m-1&&k==m-1){
                                            dp[i][k][j][l]=0;
                                    }
                                    else continue;
                            }
                        if (sameLocation(i, k, j, l)) {
                            dp[i][k][j][l] += grid[i][k];
                        }
                        else {
                            dp[i][k][j][l] += grid[i][k] + grid[j][l];
                        }
                        ans = max(ans, dp[i][k][j][l]);
                        int before = dp[i][k][j][l];
                        for (int x = 0; x < (int)(dx1.size()); ++x) {
                            int nx1 = i + dx1[x], nx2 = j + dx2[x];
                            int ny1 = k + dy1[x], ny2 = l + dy2[x];
                            int toAdd = 0;
                            if (!valid(nx1, ny1, nx2, ny2, n, m)) continue;
                            if (grid[nx1][ny1] == -1 || grid[nx2][ny2] == -1) continue;
                            dp[nx1][ny1][nx2][ny2] = max(dp[nx1][ny1][nx2][ny2], before);
                        }
                    }
                }
            }
        }
            ans=dp[0][0][0][0];
        return (ans==-1 ? 0:ans);
    }
};