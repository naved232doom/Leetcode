class Solution {
public:
    int minimumScore(vector<int>& arr, vector<vector<int>>& edges) {
        int n=(int)(arr.size());
        vector<int> X(n),deg(n);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
 
        queue<int> q;
        vector<int> vis(n);
        int S=0;
        for(int i=0;i<n;++i) {
            S^=arr[i];
            if(deg[i]==1 ) {
                q.push(i);
                vis[i]=1;
            }
            X[i]=arr[i];
        }
        int parent[n][n];
        memset(parent,0,sizeof parent);
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(!vis[v]) {
                X[v]^= X[u];
                parent[v][u]|=1;
                for(int i=0;i<n;++i) {
                    parent[v][i]|=parent[u][i];
                }    
            }
                deg[v]--;
                
//                 cout<<"u :"<<u<<endl;
//                 for(int i=0;i<n;++i){
//                     cout<<parent[u][i]<<" ";
//                 }
//                 cout<<"\n";  
//                 cout<<"v :"<<v<<endl;
//                 for(int i=0;i<n;++i){
//                     cout<<parent[v][i]<<" ";
//                 }
//                 cout<<"\n";
                if(deg[v]==1){
                    //cout<<"v :"<<v<<endl;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        int m=n-1;
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<parent[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        int ans=1e9;
        for(int i=0;i<m;++i){
            for(int j=i+1;j<m;++j){
                int a=edges[i][0],b=edges[i][1];
                int c=edges[j][0],d=edges[j][1];
                if(parent[a][b]) swap(a,b);
                if(parent[c][d]) swap(c,d);
                int c_x=X[c],a_x=X[a];
                int ans_here=0;
                int x=S;
                if(parent[a][c]){
                    x^=a_x;
                    a_x^=c_x;
                }
                else if(parent[c][a]){
                    x^=c_x;
                    c_x^=a_x;
                }
                else{
                    x^=c_x^a_x;
                }
                // cout<<"a :"<<a<<endl;
                // cout<<"b :"<<b<<endl;
                // cout<<"c :"<<c<<endl;
                // cout<<"d :"<<d<<endl;
                // cout<<"a_x :"<<a_x<<endl;
                // cout<<"c_x :"<<c_x<<endl;
                
                ans_here=max({x,a_x,c_x})-min({x,a_x,c_x});
                ans=min(ans,ans_here);
            }
        }
        return ans;
    }
};