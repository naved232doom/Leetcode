class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = (int)(trips.size());
        int maxn = 0;
        for (int i = 0; i < n; ++i) {
            maxn = max(maxn, trips[i][2]);
        }
        vector<int> pref(maxn + 1);
        for (int i = 0; i < n; ++i) {
            pref[trips[i][1]] += trips[i][0];
            pref[trips[i][2]] -= trips[i][0];
        }
        bool ok = 1;
        for (int i = 0; i < maxn + 1; ++i) {
            if (i - 1 >= 0)
                pref[i] += pref[i - 1];
            if (pref[i] > capacity) {
                ok = 0;
                break;
            }
        }

        return ok;
    }
};