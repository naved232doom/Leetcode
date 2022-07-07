class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int it1 = 0, it2 = 0;
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return false;
        int dp[n1+2][n2+2];
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
 
        for(int i=0;i<=n1;++i){
            for(int j=0;j<=n2;++j){
                if(dp[i][j] && i<n1 && s1[i]==s3[i+j]) dp[i+1][j]=1;
                if(dp[i][j] && j<n2 && s2[j]==s3[i+j]) dp[i][j+1]=1;
               
            }
        }
        return dp[n1][n2];
    }
};