class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=(int)(graph.size());
            const int inf=1e9;
            queue<array<int,3>> q;
            for(int i=0;i<n;++i){
                    q.push({(1<<i),i,0});
            }
            int visited[1<<n][n];
            memset(visited,0,sizeof visited);
            int ans=inf;
            while(!q.empty()){
                    auto cur=q.front();
                    auto mask_here=cur[0];
                    auto node_here=cur[1];
                    auto dist_here=cur[2];
                    q.pop();
                    if(mask_here==(1<<n)-1){
                            ans=min(ans,dist_here);
                            continue;
                    }
                    for(int v:graph[node_here]){
                            int mask_now=(mask_here|1<<v);
                            if(!visited[mask_now][v]){
                                    visited[mask_now][v]=1;
                                    q.push({mask_now,v,dist_here+1});
                            }
                    }
            }
            
            return ans;
    }
};