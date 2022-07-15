class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n, m;
    bool valid(int X, int Y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        return X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] && !vis[X][Y];
    }
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &cnt) {
        cnt++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nxt_x = x + dx[i], nxt_y = y + dy[i];
            if (valid(nxt_x, nxt_y, n, m, grid, vis)) {
                dfs(nxt_x, nxt_y, grid, vis, cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = (int)(grid.size());
        m = (int)(grid[0].size());
        vector<vector<int>> vis(n, vector<int>(m));
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] || !grid[i][j]) continue;
                cnt = 0;
                dfs(i, j, grid, vis, cnt);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};