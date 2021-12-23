class Solution {
        private:
        
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
            vector<int> deg(n);
            for(auto &v:pr){
                    adj[v[1]].push_back(v[0]);
                    deg[v[0]]++;
            }
            queue<int> q;
            for(int i=0;i<n;++i){
                    if(deg[i]==0){
                            q.push(i);
                    }
            }
            bool bad=0;
            int count_nodes=0;
            vector<int> ans;
            while(!q.empty()){
                    count_nodes++;
                    int cur=q.front();
                    ans.push_back(cur);
                    q.pop();
                    for(int v:adj[cur]){
                           deg[v]--;
                            if(deg[v]==0){
                                    q.push(v);
                            }
                    }
            }
            if(count_nodes!=n) return {};
            return ans;
            
    }
};