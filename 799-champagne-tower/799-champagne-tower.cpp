class Solution {
public:
    double champagneTower(int P, int r, int c) {
        int cnt_cups=0;
        double dp[r+2][r+2];
            memset(dp,0,sizeof dp);
            dp[0][0]=P;
            for(int i=0;i<=r;++i){
                    for(int j=0;j<=i;++j){
                            double rem= max((double)0,(dp[i][j]-1)/2);
                            dp[i+1][j]+=rem;
                            dp[i+1][j+1]+=rem;
                    }
            }
            cout<<dp[r][c]<<endl;
            return (dp[r][c]<= (double)1 ? dp[r][c]:1);
    }
};