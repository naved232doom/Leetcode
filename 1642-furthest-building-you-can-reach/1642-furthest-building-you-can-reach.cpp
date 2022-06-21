class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        int n = (int)(arr.size());

        int lo = 0, hi = n;
        int ans = 0;
        while (lo < hi) {
            vector<int> here;
            int mid = (lo + hi) / 2;

            bool ok = 1;
            for (int i = 1; i <= mid; ++i) {
                here.push_back(arr[i] - arr[i - 1]);
            }
            sort(here.begin(), here.end());
            int b_here = bricks, l_here = ladders;
            for (int i = 0; i < ((int)here.size()); ++i) {
                if (here[i] <= 0) continue;
                if (b_here - here[i] >= 0) {
                    b_here -= here[i];
                }
                else if (l_here) {
                    l_here--;
                }
                else ok = 0;
            }
            if (ok) {
                ans = max(ans, mid);
                lo = mid + 1;
            }
            else hi = mid;
        }
        return ans;
    }
};