class Solution {
public:
    int deleteAndEarn(vector<int>& arr) {
        int n = (int)(arr.size());
            map<int,int> V;
            for(int a:arr) V[a]+=a;
       int N=(*max_element(V.begin(),V.end())).first+1;
        vector<array<int, 2>> dp(N);
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            dp[i][0] = max(dp[i][0], max(dp[i-1][0],dp[i - 1][1]));
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + V[i]);
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;

    }
};