class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = (int)(matrix.size());
        int m = (int)(matrix[0].size());
        dp.resize(n);
        for (int i = 0; i < n; ++i) {
            dp[i].assign(m, 0);
            for (int j = 0, s_col = 0; j < m; ++j) {
                //dp[i][j]=matrix[i][j];
                s_col += matrix[i][j];
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                dp[i][j] += s_col;
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = dp[row2][col2];
        if (row1 > 0) ans -= dp[row1 - 1][col2];
        if (col1 > 0) ans -= dp[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) ans += dp[row1 - 1][col1 - 1];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */