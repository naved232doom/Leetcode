class Solution {
public:
    void dfs(vector<vector<string>> &ans, vector<int> r_c, vector<int> c_c, vector<string> g, int &n, map<int,int> mp, map<int,int> mp2, int r_here = 0) {

        if (r_here == n) {
            ans.push_back(g);
            return;
        }
        for (int j = 0, i = r_here; j < n; ++j) {
            if (c_c[j] != -1) continue;
            r_c[i] = j;
            c_c[j] = i;
            g[i][j] = 'Q';

            if (!mp.count(i - j) && !mp2.count(i + j)) {
                mp.insert({i - j,1});
                mp2.insert({i + j,1});
                dfs(ans, r_c, c_c, g, n, mp, mp2, r_here + 1);
                mp.erase(i - j);
                mp2.erase(i + j);
            }
            r_c[i] = -1;
            c_c[j] = -1;
            g[i][j] = '.';

        }

    }
    bool valid_xy(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> g;
        for (int i = 0; i < n; ++i) {
            string h = "";
            for (int j = 0; j < n; ++j) {
                h += '.';
            }
            g.push_back(h);
        }
        map<int,int> mp, mp2;
        vector<vector<string>> ans;
        vector<int> r_c(n, -1), c_c(n, -1);
        dfs(ans, r_c, c_c, g, n, mp, mp2);
        return ans;
    }
};