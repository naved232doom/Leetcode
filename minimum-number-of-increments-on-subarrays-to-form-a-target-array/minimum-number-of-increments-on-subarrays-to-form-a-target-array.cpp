class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // 1 1 2 2 3
         // order matters
            int n=(int)(target.size());
            int dp[n+1];
            memset(dp,0,sizeof dp);
            for(int i=0;i<n;++i){
                    if(i-1>=0){
                            if(target[i-1]>=target[i]){
                                    dp[i]=dp[i-1];
                            }
                            else{
                                    dp[i]=dp[i-1]+abs(target[i]-target[i-1]);
                            }
                    }
                    else{
                            dp[i]=target[i];
                    }
            }
            return dp[n-1];
    }
};