class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = (int)(arr.size());
        vector<int> pref(1, 0);
        for (int i = 0; i < n; ++i) {
            pref.push_back(pref.back() + arr[i]);
        }
        vector<int> suf(n + 1, 0);
        for (int i = n-1; i >= 0; --i) {
            suf[i] += suf[i + 1] + arr[i];
        }
        vector<array<int, 2>> p_suf;
        for (int i = n; i >= 0; --i) p_suf.push_back({suf[i], i});
        const int INF = 1e9;
        int ans = INF;
        for (int i = 0; i <= n; ++i) {
            int here = pref[i];
            if (here > x) break;
            int rem = x - here;
            array<int, 2> f = {rem, 0};
            auto it = lower_bound(p_suf.begin(), p_suf.begin()+n-i, f);
            if (it == p_suf.end()) continue;
            auto cur = *it;
            if (cur[0] != rem || i+ n-cur[1]>n) continue;
            ans = min(ans, i + n - cur[1]);
        }

        return (ans == INF ? -1 : ans);
    }
};