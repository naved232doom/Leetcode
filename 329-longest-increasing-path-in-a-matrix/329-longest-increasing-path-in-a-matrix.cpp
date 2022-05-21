class Solution {
    private:
    bool valid(int nx,int ny,int n,int m){
        return nx>=0&&ny>=0&&nx<n&&ny<m;
    }
    void dfs(int u,vector<vector<int>> &adj,vector<int> &order,vector<int> &vis){
        vis[u]=1;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,order,vis);
            }
        }
        order.push_back(u);
    }
    void dfs2(int u,vector<vector<int>> &adj,vector<int> &dp){
        
        for(int v:adj[u]){
            if(dp[u]+1>dp[v]){
                dp[v]=dp[u]+1;
                dfs2(v,adj,dp);
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& g) {
        int n=(int)(g.size());
        int m=(int)(g[0].size());
        vector<vector<int>> adj(n*m+1);
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                for(int k=0;k<4;++k){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(valid(nx,ny,n,m)&&g[nx][ny]>g[i][j]){
                        adj[i*m+j].push_back(nx*m+ny);
                    }
                }
            }
        }
        // topsort;
        vector<int> dp(n*m+1);
        vector<int> order;
        vector<int> vis(n*m+1);
        for(int i=0;i<n*m;++i){
            if(!vis[i]){
                dfs(i,adj,order,vis);
            }
        }
        reverse(order.begin(),order.end());
        vis=vector<int>(n*m);
        for(int u:order){
            if(!vis[u]){
                dfs2(u,adj,dp);
            }
        }
       int ans=*max_element(dp.begin(),dp.end());
        return ans+1;
    }
};