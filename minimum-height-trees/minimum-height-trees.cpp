class Solution {
        private:
        typedef pair<int,int> pii;
        vector<int> getPath(vector<int> &parent,int u){
                vector<int> path;
                while(u!=-1){
                        path.push_back(u);
                        u=parent[u];
                }
                return path;
        }
int bfs(vector<vector<int>> &adj,int n,int start){
       vector<int> dist(n,INT_MAX);    
        priority_queue<pii,vector<pii>,greater<pii>> q;
        dist[start]=0;
        q.push({dist[start],start});
        while(!q.empty()){
                auto u=q.top();
                q.pop();
                int cur=u.second;
                for(int v:adj[cur]){
                        if(dist[v]>dist[cur]+1){
                                dist[v]=dist[cur]+1;
                                q.push({dist[v],v});
                        }
                }
        }
        int maxNode=0;
                for(int i=0;i<n;++i){
                        if(dist[i]>dist[maxNode]){
                                maxNode=i;
                        }
                }
        return maxNode;
}
 int tracePath(int u,int p,int en,vector<vector<int>> &adj,vector<int> &parent){
               
         for(int v:adj[u]){
                 if(v==p) continue;
                 else if(v==en){
                         parent[u]=v;
                         return 1;
                 }
                 else{
                         if(tracePath(v,u,en,adj,parent)){
                                 parent[u]=v;
                                 return 1;
                         }
                         
                         
                 }
         }
         return 0;
 }       
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
            vector<vector<int>> adj(n);
            for(auto &p:edges){
                    adj[p[0]].push_back(p[1]);
                    adj[p[1]].push_back(p[0]);
            }
           int diameterEnd1= bfs(adj,n,0);
           int diameterEnd2=bfs(adj,n,diameterEnd1);
            vector<int> parent(n,-1);
            tracePath(diameterEnd2,-1,diameterEnd1,adj,parent);
            vector<int> path;
        int s=diameterEnd2;
            path=getPath(parent,s);
            //cout<<diameterEnd1<<" "<<diameterEnd2<<"\n";
            // while(s!=-1){
            //         path.push_back(s);
            //         s=parent[s];
            // }
            // for(int v:path){
            //         cout<<v<<" ";
            // }
            //cout<<endl;
            int len=(path.size());
            vector<int> ans;
            if(len%2){
                    ans.push_back(path[len/2]);
            }
            else{
                    ans.push_back(path[len/2]);
                    ans.push_back(path[len/2-1]);
            }
            return ans;
            
            
            }
};