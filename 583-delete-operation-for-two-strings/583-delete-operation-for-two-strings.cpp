class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=(word1.size());
        int m=(word2.size());
        const int INF=1e9;
        vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
        dp[0][0]=0;
        for(int i=0;i<=n;++i){
            dp[i][0]=i;
        } 
        for(int i=0;i<=m;++i){
            dp[0][i]=i;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i+1][j]+1);
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j+1]+1);
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
                
            }
        }
        
        return dp[n][m];
    }
};