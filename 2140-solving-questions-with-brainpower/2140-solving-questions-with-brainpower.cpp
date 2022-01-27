class Solution {
    typedef long long int ll;
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = (int)questions.size();
        vector<ll> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            ll b_power = questions[i][1];
            ll points_here = questions[i][0];
            ll to_jump = min((ll)n, (ll)(i + b_power + 1));
            dp[i] = max(dp[i], dp[to_jump] + points_here);
            dp[i] = max(dp[i], dp[i + 1]);
        }

        return dp[0];
    }
};