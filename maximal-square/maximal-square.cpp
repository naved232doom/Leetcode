class Solution {
private:
        bool valid(int x,int y,int n,int m){
                return x>=0&&x<n&&y>=0&&y<m;
        }
        int getOnes(vector<vector<int>> &dp,int x,int y,int nx,int ny){
                int64_t ans=0;
                ans+=dp[nx][ny];
                // x,ny nx,y
                if(x-1>=0)
                ans-=dp[x-1][ny];
                if(y-1>=0)
                ans-=dp[nx][y-1];
                if(x-1>=0&&y-1>=0)
                ans+=dp[x-1][y-1];
                return ans;
        }
bool possible(vector<vector<int>>& dp,int mid,int n,int m){
         
        for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                        int nextI=i+mid-1;
                        int nextJ=j+mid-1;
                        if(valid(nextI,nextJ,n,m)){
                            int ones=getOnes(dp,i,j,nextI,nextJ);
                                if(ones==mid*mid){
                                        return 1;
                                }
                        }
                }
        }
                
        return 0;
}    
public:
int maximalSquare(vector<vector<char>>& matrix) {
        // m*n*log(min(n,m))
            // 9e4*8
            int n=(int)(matrix.size()),m=(int)(matrix[0].size());
                vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                        int now=0;
                        if(matrix[i][j]=='1') now=1;
                        dp[i][j]+=now ;
                        if(i-1>=0) dp[i][j]+=dp[i-1][j];
                        if(j-1>=0) dp[i][j]+=dp[i][j-1];
                        if(i-1>=0&&j-1>=0) dp[i][j]-=dp[i-1][j-1];
                        //cout<<dp[i][j]<<" ";
                }
                //cout<<"\n";
        }
            int lb=0,rb=min(m,n)+1;
        int ans=0;
            while(lb<rb){
                    int mid=(lb+rb)/2;
                    if(possible(dp,mid,n,m)){
                            //cout<<mid<<endl;
                            ans=max(ans,mid);
                               lb=mid+1; 
                    }
                    else rb=mid;
            }
        return ans*ans;
    }
};