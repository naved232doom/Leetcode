class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i)
        {
            if (p[i] == '*' && dp[0][i - 1])
                dp[0][i + 1] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*')
                {
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else
                        dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1];
                }
                else
                    dp[i + 1][j + 1] = dp[i][j] && (p[j] == s[i]);
            }
        }
        return dp[m][n];
    }
};