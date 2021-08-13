class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
                int n=text1.length();
            int m=text2.length();
            vector<vector<int>> dp(2,vector<int> (m+1));
            // dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i][j]);
            // parity=i&1;
            // dp[parity][j]=max(dp[parity^1][j],dp[parity][j-1]);
                
            for(int i=0;i<n;++i){
                    int parity=(i+1)&1;
                for(int j=0;j<m;++j){
                        dp[parity][j+1]=max(dp[parity^1][j+1],dp[parity][j]);
                if(text1[i]==text2[j]){
                        dp[parity][j+1]=max(dp[1^parity][j]+1,dp[parity][j+1]);
                                    
                        }
                }
            }
            return dp[n&1][m];
    }
};