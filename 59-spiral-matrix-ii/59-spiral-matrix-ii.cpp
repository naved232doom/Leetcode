class Solution {
private:
    int valid(int x, int n) {
        return x >= 0 && x < n;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0, y = 0, k = 0;
        ans[0][0] = 1;
        for (int it = 2; it <= n * n;) {
            while (it <= n * n) {
                // cout<<x<<" "<<y<<endl;
                // cout<<it<<endl;
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, n) && valid(ny, n) && ans[nx][ny] == -1) {
                    x = x + dx[k]; y = y + dy[k];
                    ans[x][y] = it++;
                }
                else break;


            }
            // cout<<x<<" "<<y<<endl;
            k++;
            k %= 4;
        }
        return ans;
    }
};