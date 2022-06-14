class Solution {
public:
    int superEggDrop(int K, int n) {
        int ans=0;
        vector<vector<int>> dp(2,vector<int>(K+1));
        while(dp[ans%2][K]< n){
            ans++;
            for(int i=1;i<=K;++i){
                dp[ans%2][i]=dp[(ans+1)%2][i-1]+dp[(ans+1)%2][i]+1;
            }
        }
        return ans;
    }
};