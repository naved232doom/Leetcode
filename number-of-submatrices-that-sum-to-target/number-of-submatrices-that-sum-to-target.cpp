class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = (int)(matrix.size());
        int m = (int)(matrix[0].size());
        int pref[n][m];
        memset(pref, 0, sizeof pref);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j - 1 >= 0) {
                    pref[i][j] += pref[i][j - 1] + matrix[i][j];
                }
                else {
                    pref[i][j] += matrix[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                int cur_sum = 0;
                map<int, int> count_sums;
                count_sums[0] = 1;
                for (int k = 0; k < n; ++k) {
                    if (i - 1 >= 0) {
                        cur_sum += pref[k][j] - pref[k][i - 1];
                    }
                    else cur_sum += pref[k][j];
                    int to_find = cur_sum - target;
                    if (count_sums.find(to_find) != count_sums.end()) {
                        // cout<<i<<" "<<j<<" "<<k<<"\n";
                        // cout<<cur_sum<<endl;
                        // cout<<to_find<<" "<<count_sums[to_find]<<"\n";
                        ans += count_sums[to_find];
                    }
                    count_sums[cur_sum]++;
                }
            }
        }
        return ans;
    }
};