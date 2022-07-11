class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=(int)(cost.size());
        const int INF=1e9;
        vector<int> dp(n+5,INF);
        dp[0]=0;
        dp[1]=0;
        for(int i=0;i<n;++i){
            dp[i+1]=min(dp[i+1],dp[i]+cost[i]);
            dp[i+2]=min(dp[i+2],dp[i]+cost[i]);
        }
        return dp[n];
    }
};