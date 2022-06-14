class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        const int INF = (int)1e9;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=s1[i];
        }
        for(int i=0;i<m;++i){
            sum+=s2[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]) ;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
                if (s1[i] == s2[j]) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (int)(s1[i]));
                }
            }
        }

        return sum- 2*dp[n][m] ;
    }
};