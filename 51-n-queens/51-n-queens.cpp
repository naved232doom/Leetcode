class Solution {
public:void dfs(vector<vector<string>> &ans,vector<int> r_c,vector<int> c_c,vector<string> g,int &n,int &m,int r_here=0){
        if(r_here==n){
            ans.push_back(g);
            return;
        }

        for(int j=0,i=r_here;j<m;++j){
            if(c_c[j]!=-1) continue;
                r_c[i]=j;
                c_c[j]=i;
                g[i][j]='Q';
             if(works(g,r_here,j,n,m)){
                    
                 dfs(ans,r_c,c_c,g,n,m,r_here+1);
             }
                r_c[i]=-1;
                c_c[j]=-1;
                g[i][j]='.';
            
        }
        
    }
    bool works(vector<string> g,int x,int y,int n,int m){
        bool ok=1;
        vector<int> dx={-1,1,1,-1};
        vector<int> dy={1,-1,1,-1};
    for(int i=0;i<4;++i){
        int t_x=x+dx[i],t_y=y+dy[i];
        while(valid_xy(t_x,t_y,n,m)){
           if(g[t_x][t_y]=='Q') return 0;
            t_x+=dx[i];
            t_y+=dy[i];
        }
    }
        
        return 1;
    }
    bool valid_xy(int x,int y,int n,int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> g;
        for(int i=0;i<n;++i){
            string h="";
            for(int j=0;j<n;++j){
                h+='.';
            }
            g.push_back(h);
        }
        vector<vector<string>> ans;
        vector<int> r_c(n,-1),c_c(n,-1);
        dfs(ans,r_c,c_c,g,n,n);
        return ans;
    }
};