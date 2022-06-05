class Solution {
public:
    int numSquarefulPerms(vector<int>& arr) {
        int n = (int)(arr.size());
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int s_here = arr[i] + arr[j];
                int r_here = sqrt(s_here);
                if (r_here * r_here == s_here) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        map<int,int> mp;
        queue<pair<array<int, 2>, vector<int>>> q;
        vector<vector<int>> pref[n + 1];
        for (int i = 0; i < n; ++i) {
            if(mp.find(arr[i])!=mp.end()) continue;
            q.push({{(1 << i), i}, {arr[i]}});
            pref[1].push_back({i});
            mp[arr[i]]=1;
        }
        int ans = 0;
        while (!q.empty()) {
            auto c = q.front(); q.pop();
            auto x = c.second;
            auto cur = c.first;
            auto mask = cur[0];
            auto u = cur[1];
            for (int v : adj[u]) {
                if ((mask & (1 << v))) continue;
                int mask_here = mask | (1 << v);
                auto x_here = x;
                x_here.push_back(arr[v]);
                int len = (int)(x_here.size());
                bool bad = 0;
                for (auto p : pref[len]) {
                    if (p == x_here) {
                        bad = 1;
                    }
                }
                if (bad) continue;

                if (mask_here == ((1 << n) - 1)) {
                    ans++;
                }
                else {
                    q.push({{mask_here, v}, x_here});
                    pref[len].push_back(x_here);
                }
            }

        }
        int div = 1;
        
        return ans / div;
        // 1 -> [8]
        // 17 -> [8]
        // 8 -> [1,17]
    }
};