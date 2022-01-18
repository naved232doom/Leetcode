class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 1;
        int n = (int)(seats.size());
        vector<int> suff(n + 1, 2 * n);

        for (int i = n - 1; i >= 0; --i) {
            suff[i] = min(suff[i], suff[i + 1]);
            if (seats[i] == 1) {
                suff[i] = min(suff[i], i);
            }
        }
        int left = (seats[0]==1 ? 0:-n);
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                left = max(left, i);
                continue;
            }

            ans = max(ans, min(i - left, suff[i] - i));
        }
        return ans;
    }
};