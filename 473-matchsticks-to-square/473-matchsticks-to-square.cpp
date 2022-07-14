class Solution {
public:
    typedef long long ll;
    int dfs(vector<int> &arr, int idx, vector<ll> &cnt, ll &S) {
        int n = (int)(arr.size());
        ll s_here = 0;
        int count = 0;
        for (int v : cnt) if (v == S / 4) count++;
        if(count==3) return 1;
        if (idx == n) {
            if (count == 4) return 1;
            return 0;
        }
        for (int m = 0; m < 4; ++m) {
            if (arr[idx] + cnt[m] > S / 4) continue;
            cnt[m] += arr[idx];
            if (dfs(arr, idx + 1, cnt, S)) return 1;
            cnt[m] -= arr[idx];
        }

        return 0;
    }
    bool makesquare(vector<int>& arr) {
     
        int n = (int)(arr.size());
        ll S = 0;
        sort(arr.rbegin(), arr.rend());
        for (ll v : arr) S += v;
        if (S % 4) return false;
        vector<ll> cnt(4);
        return dfs(arr, 0, cnt, S);
    }
};