class Solution {
public:
    typedef long long int ll;
    vector<long long> getDistances(vector<int>& arr) {
        int n = (int)(arr.size());
        const int maxn = 1e5 + 5;
        vector<ll> suf(maxn), pref(maxn), suf_count(maxn), pref_count(maxn);
        vector<ll> ans(n);
        for (int i = 0; i < n; ++i) {
            pref[arr[i]] += i;
            pref_count[arr[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            pref[arr[i]] -= i;
            pref_count[arr[i]]--;
            int before = suf[arr[i]];
            ll after = pref[arr[i]];
            ll here = pref[arr[i]] - i * pref_count[arr[i]];
            here += (i * suf_count[arr[i]] - suf[arr[i]]);
            suf[arr[i]] += i;
            suf_count[arr[i]]++;
            ans[i] = here;
        }

        return ans;
    }
};