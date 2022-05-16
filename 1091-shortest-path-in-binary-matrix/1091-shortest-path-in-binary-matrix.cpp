class Solution {
// struct P{
//     int x,y;
//     P(int x,int y){
//         this->x=x;
//         this->y=y;
//     }
// };
    private:
    bool is_valid(int nx,int ny,int n){
        return nx>=0&&ny>=0&&nx<n&&ny<n;
    }
    typedef pair<int,int> pii;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=(int)(grid.size());
        queue<pii> q;
        if(grid[0][0]==1) return -1;
        q.push({0,0});
        const int inf=1e9;
        vector<vector<int>> dp(n,vector<int> (n,inf));
        vector<int> dx={-1,1,0,0,1,1,-1,-1};
        vector<int> dy={0,0,-1,1,1,-1,-1,1};
        dp[0][0]=1;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int x=cur.first,y=cur.second;
            for(int i=0;i<8;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(!is_valid(nx,ny,n)||grid[nx][ny]==1) continue;
                if(dp[nx][ny]>dp[x][y]+1){
                    dp[nx][ny]=min(dp[x][y]+1,dp[nx][ny]);
                    q.push({nx,ny});
                }
            }
        }
        return ( dp[n-1][n-1]==inf ? -1:dp[n-1][n-1]);
    }
};