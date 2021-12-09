class Solution {
        private:
        vector<vector<int>> getGraph(vector<int> &arr){
                int N=(int)arr.size();
                vector<vector<int>> adj(N+1);
                for(int i=0;i<N;++i){
                        int cur=arr[i];
                        int prevIndex=i-cur,nextIndex=cur+i;
                        if(prevIndex>=0){
                                adj[i].push_back(prevIndex);
                        }
                        if(nextIndex<N){
                                adj[i].push_back(nextIndex);
                        }
                }
                return adj;
        }
        bool dfs(vector<vector<int>> &adj,vector<int> &arr,int u,vector<int> &visited){
                if(arr[u]==0) return 1;
                visited[u]=1;
                for(int v:adj[u]){
                        if(arr[v]==0) return 1;
                        if(visited[v]) continue;
                         if(dfs(adj,arr,v,visited)) return 1;
                }
                return 0;
        }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<vector<int>> adj=getGraph(arr);
            vector<int> visited((int)(arr.size()));
           return dfs(adj,arr,start,visited);
    }
};