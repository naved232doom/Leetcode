class Solution {
public:
    int find_edges(int mask, vector<vector<int>> &dp) {
        int n = (int)(dp.size());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << i)) && (mask & (1 << j)) && dp[i][j] == 1) ans++;
            }
        }
        return ans;
    }
    int find_dist(int mask, vector<vector<int>> &dp) {

        int n = (int)(dp.size());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << i)) && (mask & (1 << j))) ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        const int inf = 1e6;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
        for (auto e : edges) {
            int u = e[0], v = e[1];
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            dp[u][v] = dp[v][u] = 1;
        }
        for(int i=0;i<n;++i) dp[i][i]=0;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
           
        vector<int> ans(n - 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt_v = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) cnt_v++;
            }
            int cnt_edges = find_edges(mask, dp);
            //cout<<cnt_edges<<" " <<cnt_v<<" "<<mask<<endl;
            if (cnt_edges != cnt_v - 1) continue;
            int max_dist = find_dist(mask, dp);
            //cout<<"max_dist "<<max_dist<<endl;
            if (max_dist == 0) continue;
            ans[max_dist - 1]++;

        }
        return ans;
    }
};