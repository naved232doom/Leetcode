class Solution {
    private:
    const int INF= (int)(1e9);
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INF);
        int n=(int)(coins.size());
        dp[0]=0;
        for(int i=0;i<=amount;++i){
            for(int j=0;j<n;++j){
                int prev=i-coins[j];
                if(prev>=0){
                    dp[i]=min(dp[i],dp[prev]+1);
                }
            }
        }
        
        return (dp[amount] == INF ? -1:dp[amount]);
    }
};