class Solution {
    int is_subs(string &a, string &b) {
        int n = a.length(), m = b.length();
        int i = 0, j = 0;
        for (; i < n && j < m;) {
            if (a[i] == b[j]) {
                i++; j++;
            }
            else {
                j++;
            }
        }
        return i == n && m == n + 1;
    }
public:
    int longestStrChain(vector<string>& words) {
        // sort(words.begin(),words.end(),[](string a,string b){
        //     return (int)a.length()< (int)b.length();
        // });
        int n = (int)(words.size());
        vector<int> dp(n, 1);
        vector<vector<pair<string, int>>> adj(20);
        int it = 0;
        for (auto s : words) {
            adj[s.length()].push_back({s, it++});
        }
        int ans = 1;
        for (int i = 0; i < 18; ++i) {
            for (auto q : adj[i]) {
                for (auto p : adj[i + 1]) {
                    auto idx = p.second;
                    auto s_here = p.first;
                    if (is_subs(q.first, s_here)) {
                        dp[idx] = max(dp[idx], dp[q.second] + 1);
                        ans = max(ans, dp[idx]);
                    }
                }
            }
        }
        return ans;
    }
};