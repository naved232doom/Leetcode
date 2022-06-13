class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (is_sorted(arr.begin(), arr.end())) return     *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
        int K = 2;
        int n = (int)(arr.size());
        const int NINF = -(int)1e9;
        vector<vector<int>> dp(n, vector<int>(K + 1));
        // dp[i][k]=max(dp[i][k], prices[i]+dp[j][k-1]-prices[j])
        int ans = 0;
        for (int k = 1; k <= K; ++k) {
            int prev = NINF;
                //prev = max(prev, dp[0][k - 1] - arr[0]);
            for (int i = 0; i < n; ++i) {
                if(i)
                dp[i][k] = max(dp[i-1][k], arr[i] + prev);
                prev = max(prev, dp[i][k - 1] - arr[i]);
                ans = max(ans, dp[i][k]);
            }
        }

        return ans;

    }
};