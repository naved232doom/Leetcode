class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {

        vector<vector<int>> adj(n), adjt(n);
        vector<int> deg(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            u--; v--;
            adj[u].push_back(v);
            adjt[v].push_back(u);
            deg[v]++;
        }

        queue<int> q;
        int ans = 0;
        vector<int> vis(n);
        vector<int> dist(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (deg[i] == 0) {
                dist[i]=time[i];
                q.push(i);
            }
        }
        while (!q.empty()) {
            int len = (int)(q.size());
            int ans_here = 0;
            int u = q.front();
            vis[u] = 1;
            q.pop();
            for (int v : adj[u]) {
                dist[v]=max(dist[v],dist[u]+time[v]);
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                }
            }

        }
        ans=*max_element(dist.begin(),dist.end());
        return ans;
    }
};