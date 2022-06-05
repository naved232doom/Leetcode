class Solution {
private: void solve( int &n, int &ans, vector<int> c_p, map<int, int> m1, map<int, int> m2, int r_here = 0) {
        if (r_here == n) {
            ans++;
            return;
        }
        for (int j = 0, i = r_here; j < n; ++j) {
            if (c_p[j] != -1) continue;
            int sum = i + j, dif = i - j;
            if (m1.count(sum) || m2.count(dif)) continue;
            c_p[j] = i;
            m1.insert({sum, 1});
            m2.insert({dif, 1});
            //g[i][j] = 1;
            solve( n, ans, c_p, m1, m2, r_here + 1);
            c_p[j] = -1;
            //g[i][j] = 0;
            m1.erase(sum);
            m2.erase(dif);
        }

    }
public:
    int totalNQueens(int n) {
       
        int ans = 0;
        vector<int> c_p(n, -1);
        map<int, int> m1, m2;
        solve( n, ans, c_p, m1, m2);
        return ans;
    }
};