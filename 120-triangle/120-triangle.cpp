class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=(t.size());
        auto dp=t;
        for(int i=1;i<n;++i)
        {
            int m=(int)(t[i].size());
            for(int j=0;j<m;++j){
                    int here=dp[i][j];
                    dp[i][j]=(int)1e9;
                    if(j<m-1)
                    dp[i][j]=here+dp[i-1][j];
                    if(j-1>=0){
                        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+here);
                    }
            }
            
        }
        
        return *min_element((dp[n-1]).begin(),(dp[n-1]).end());
    }
};