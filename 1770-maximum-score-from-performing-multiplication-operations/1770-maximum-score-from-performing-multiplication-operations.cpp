class Solution {
public:
    int maximumScore(vector<int>& arr, vector<int>& M) {
        int n=(int)(arr.size());
        int k=(int)(M.size());
        const int INF=(int)(1e9+5);
        vector<vector<int>> dp(k+1,vector<int>(k+1,-INF));
        dp[0][0]=0;
        int ans=-INF;
        // dp[l][r]
        // dp[l+1][r]=min(dp[l][r]+)
    for(int len=1;len<=k;++len){
        for(int i=0;i<=len;++i){
             int l_t=i,r_t=len-i;
            if(l_t-1>=0)
dp[l_t][r_t]=max(dp[l_t][r_t],dp[l_t-1][r_t]+arr[l_t-1]*M[len-1]);
            if(r_t-1>=0)
dp[l_t][r_t]=max(dp[l_t][r_t],dp[l_t][r_t-1]+arr[n-r_t]*M[len-1]);    
        }
    }
        for(int l=0;l<=k;++l){
            ans=max(ans,dp[l][k-l]);
        }
       
        return ans;
    }
};