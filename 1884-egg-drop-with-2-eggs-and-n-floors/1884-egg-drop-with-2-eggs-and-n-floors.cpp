class Solution {
public:
       const int INF=1e9;
    int go(vector<vector<int>> &dp,int x,int eggs_rem){
        if(dp[eggs_rem][x]!=INF) return dp[eggs_rem][x];
        //if(x<=1 || eggs_rem==1) return dp[x][eggs_rem]=x;
        if(eggs_rem==1) return dp[eggs_rem][x]=x;
        //if()
        for(int i=1;i<=x;++i){
            //int &here=dp[eggs_rem][x];
            //dp[eggs_rem][x]=1+;
            int ans_here=-INF;
            if(x-i){
                ans_here=go(dp,x-i,eggs_rem);
            }
            ans_here=max(ans_here,go(dp,i-1,eggs_rem-1));
            dp[eggs_rem][x]=min(dp[eggs_rem][x],1+ans_here);
        }
        return dp[eggs_rem][x]; 
    }
    int twoEggDrop(int n) {
        int K=2;
        vector<vector<int>> dp(K+1,vector<int>(n+1,INF));
        for(int i=1;i<=K;++i) dp[i][0]=0;
        for(int i=1;i<=K;++i) dp[i][1]=1;
        go(dp,n,K);

        return dp[K][n];
    }
};