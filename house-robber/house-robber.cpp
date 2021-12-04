class Solution {
public:
    int rob(vector<int>& nums) {
            int n=(int)(nums.size());
        vector<int> dp(n+1);
            dp[1]=nums[0];
            for(int i=1;i<n;++i){
                    dp[i+1]=dp[i];
                    if(i-1>=0) dp[i+1]=max(dp[i+1],dp[i-1]+nums[i]);
            }
            int ans=0;
            for(int i=0;i<=n;++i) ans=max(ans,dp[i]);
            return ans;
    }
};