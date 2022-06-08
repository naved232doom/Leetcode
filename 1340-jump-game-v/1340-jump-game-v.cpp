class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = (int)(arr.size());
        const int INF = 1e9;
        vector<int> dp(n, -INF);
        vector<array<int, 2>> pos;
        for (int i = 0; i < n; ++i) {
            pos.push_back({arr[i], i});
        }
        sort(pos.begin(), pos.end());
        for (int i = 0; i < n; ++i) {
            auto cur = pos[i];
            auto u = cur[0];
            auto v = cur[1];
            dp[v] = max(dp[v], 1);
            for (int j = 1; j <= d && v + j < n; ++j) {
                if (arr[v + j] >= arr[v]) break;
                dp[v] = max(dp[v], 1 + dp[v + j]);
            }
            for (int j = 1; j <= d && v - j >= 0; ++j) {
                if (arr[v - j] >= arr[v]) break;
                dp[v] = max(dp[v], 1 + dp[v - j]);
            }

        }

        return *max_element(dp.begin(), dp.end());
    }
};