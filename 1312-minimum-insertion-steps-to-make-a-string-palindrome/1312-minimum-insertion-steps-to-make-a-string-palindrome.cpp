class Solution {
public:
    int minInsertions(string s) {
        
        int n=(int)(s.size());
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int i=1;i<=n;++i){
            dp[i][i]=1;
        }
        
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i]==s[j]){
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+2][j]+2);
                }
                else{
                    dp[i+1][j+1]=max(dp[i+1][j],max(dp[i+1][j+1],dp[i+2][j+1]));
                }
            }
        }
        // for(int i=1;i<=n;++i){
        //     for(int j=i;j<=n;++j){
        //         cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        //     }
        // }
        return n-dp[1][n];
    }
};