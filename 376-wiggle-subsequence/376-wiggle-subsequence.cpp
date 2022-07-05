class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n=(int)(arr.size());
        vector<vector<int>> dp(n,vector<int>(2,1));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(arr[i]==arr[j]) continue;
                if(arr[j]<arr[i])
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
                else
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }
        }
        int ans=1;
        for(int i=0;i<n;++i) {
            ans=max(ans,max(dp[i][1],dp[i][0]));
        }
        return ans;
    }
};