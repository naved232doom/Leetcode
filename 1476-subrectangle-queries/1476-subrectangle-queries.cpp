class SubrectangleQueries {
public:
    bool in_range(int r, int r1, int r2) {
        return r >= r1 && r <= r2;
    }
    vector<vector<int>> arr;
    int n, m;
    vector<array<int, 5>> Q;
    SubrectangleQueries(vector<vector<int>>& R) {
        n = (int)(R.size());
        m = (int)(R[0].size());
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                arr[i].push_back(R[i][j]);
            }
        }
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        Q.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        int len = (Q.size());
        for (int i = len - 1; i >= 0; --i) {
            if (in_range(row, Q[i][0], Q[i][2]) && in_range(col, Q[i][1], Q[i][3])) {
                return Q[i][4];
            }
        }
        return arr[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */