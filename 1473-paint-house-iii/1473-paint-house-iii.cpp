class Solution {
public:
    int minCost(vector<int>& H, vector<vector<int>>& cost, int n, int m, int T) {
        // dp[i][j][k]
        for (auto &h : H) {
            h--;
        }
        
        int dp[n + 1][T + 1][m + 1];
        const int INF = (int)(1e9);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= T; ++j) {
                for (int k = 0; k <= m; ++k) {
                    dp[i][j][k] = INF;
                }
            }
        }
        //
        
        for (int i = 0; i <= m; ++i) dp[0][0][i] = 0;
        // if(H.front()==-1){
        //     for(int c=0;c<m;++c){
        //         dp[1][1][c]=cost[0][c];
        //     }
        // }
        // else{
        //     dp[1][1][H[0]]=cost[0][H[0]];
        // }
     
        for (int i = 0; i < n; ++i) {

            for (int j = 0; j <= T; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (H[i] >= 0) {
                        if (k == H[i]) {
                    int j_here=max(j,1);
    dp[i + 1][j_here][H[i]] = min(dp[i + 1][j_here][H[i]], dp[i][j][k] + cost[i][H[i]]);
                        }
                        else if(j<T) {

        dp[i + 1][j + 1][H[i]] = min(dp[i + 1][j + 1][H[i]], dp[i][j][k] + cost[i][H[i]]);
                        }
                        continue;
                    }
                    for (int l = 0; l < m; ++l) {
                        if (k == l) {
                            int j_here=max(j,1);
            dp[i + 1][j_here][l] = min(dp[i + 1][j_here][l], dp[i][j][k] + cost[i][l]);
                        }
                        else if(j<T){
            dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][k] + cost[i][l]);

                        }
                    }
                }
            }
        }
        int prev=0;
        for(int i=0;i<n;++i){
            if(H[i]>=0){
                prev+=cost[i][H[i]];
            }
        }
        int ans = INF;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, dp[n][T][i]);
        }
        return (ans== INF ? -1:ans-prev);
    }
};