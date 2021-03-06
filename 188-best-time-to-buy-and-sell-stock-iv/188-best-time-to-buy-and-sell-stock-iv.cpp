class Solution {
public:
    int maxProfit(int K, vector<int>& arr) {
        int n=(int)(arr.size());
        if(n <= 1) return 0;
        int dp[n+1][K+1];
        memset(dp,0,sizeof dp);
        int ans=0;
        const int INF=(int)(1e9);
        for(int k=1;k<=K;++k){
        // dp[i][k] = ckmin dp[i-1][k], max(dp[j-1][k-1] - prices[j]) +prices[i] 
            int prev_max=-arr[0];
            for(int i=0;i<n;++i){
                if(i)
                dp[i][k]=max(dp[i][k],dp[i-1][k]);
                dp[i][k]=max(dp[i][k],prev_max+arr[i]);
                if(i)
                prev_max=max(prev_max,dp[i-1][k-1]-arr[i]);
            }
        }
        return dp[n-1][K];
    }
};