class Solution {
public:
        typedef long long ll;
    int numTilings(int n) {
            const int mod=1e9+7;
            if(n==0) return 1;
        vector<ll> dp(n+2);
            dp[0]=1;
            
            for(int i=1;i<=n;++i){
                if(i-1>=0) {
                        dp[i]+=dp[i-1];
                        dp[i]%=mod;
                } 
                if(i-2>=0){
                        dp[i]+=dp[i-2];
                        dp[i]%=mod;
                }    
                for(int j=i-3;j>=0;--j){
                        dp[i]+=2*dp[j];
                        dp[i]%=mod;
                }    
            }
            
            return dp[n];
    }
};