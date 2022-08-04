class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;++i) dp[i][i]=1;
        
        // cbabcad
        for(int j=0;j<n;++j){
            for(int i=0;i<=j;++i){
                if(s[i]!=s[j]) continue;
                int I=i+1,J=j-1;
                if(j>i && j-i+1==2) 
                {
                    dp[i][j]=2;
                    continue;
                }
                if(I>J) continue;
                if(dp[I][J]) dp[i][j]=1;
            }
        }
        int len=1;
        int beg=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(!dp[i][j]) continue;
                int len_here=j-i+1;
                if(len_here>len){
                    len=len_here;
                    beg=i;
                }
            }
        }
        return s.substr(beg,len);
       
    }
};