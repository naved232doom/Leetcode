class Solution {
public:
    string longestPalindrome(string s) {
        int n=(int)(s.size());
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;++i) dp[i][i]=1;
        
        for(int len=2;len<=n;++len){
            for(int i=0;i<n;++i){
                int r=i+len-1;
                int l=i;
                if(r >= n) continue;
                if(s[i]!=s[r]) continue;
                if(r-1<l+1 || dp[l+1][r-1]){
                    dp[l][r]|=1;
                }
            }
        }
        int ans=1,l=0,r=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(!dp[i][j]) continue;
                int len= j-i+1;
                if(len > ans) {
                    ans=len;
                    l=i;
                    r=j;
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};