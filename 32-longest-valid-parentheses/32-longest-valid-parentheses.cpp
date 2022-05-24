class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        s=')'+s;
        int n=s.length();
        vector<int> dp(n+1,0);
        int open_cnt=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(') open_cnt++;
            else if(open_cnt>0){
                dp[i]=max(dp[i],dp[i-1]+2);
                int prev_idx=i-dp[i];
                if(prev_idx>0){
                    dp[i]+=dp[prev_idx];
                }
                open_cnt--;
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};