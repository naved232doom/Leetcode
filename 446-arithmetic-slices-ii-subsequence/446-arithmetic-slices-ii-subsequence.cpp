class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& arr) {
        // there can only be n*n differences ~ 1e6
        int ans = 0;
        int n = (int)(arr.size());
        vector<map<ll, int>> mp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll dif = (ll)arr[j] - arr[i];
                ll cnt = (mp[j].find(dif) == mp[j].end() ? 0 : mp[j][dif]);
                ans += cnt;
                mp[i][dif] += cnt + 1;
            }
        }
        return ans;

    }
};