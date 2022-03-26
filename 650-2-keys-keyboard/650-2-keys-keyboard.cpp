class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        // sequence should be monotonous
        // starts with 1
        const int inf=1e9+7;
        vector<int> dp(2*n+5,inf);
        dp[0]=0;
        dp[1]=0;
        //queue<int> q;
        for(int i=2;i<=n;++i){
            dp[i]=i;
            for(int k=i;k>1;--k){
                if(i%k==0)
                dp[i]=min(dp[i],dp[k]+i/k);
            }
        }
        ans=dp[n];
        return ans;
    }
};