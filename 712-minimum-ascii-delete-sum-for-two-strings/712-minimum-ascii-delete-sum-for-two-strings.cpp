class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        const int INF=(int)1e9;
        vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
        for(int i=0,S=0;i<=n;++i){
            dp[i][0]=S;
            S+= ( i < n ? s1[i]:0);
        } 
        for(int i=0,S=0;i<=m;++i){
            dp[0][i]=S;
            S+= ( i < m ? s2[i]:0);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i+1][j]+(int)s2[j]);
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j+1]+(int)s1[i]);
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};