class Solution {
public:
    int maximumGood(vector<vector<int>>& arr) {
        int n = (int)(arr.size());
        int ans = 0;
        auto check_ans = [&](int mask) {

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < n; ++j) {
                        int i_says = arr[i][j];
                        int j_good = (mask & (1 << j)) > 0 ? 1 : 0;
                        if ((i_says == 1 && j_good == 0) || (i_says == 0 && j_good == 1)) return 0;

                    }
                }
            }

            return 1;
        };
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt_bits = 0;
            for (int i = 0; i < n; ++i) {
                cnt_bits += (mask & (1 << i) ? 1 : 0);
            }
            if (check_ans(mask)) {
                //cout << mask << endl;
                ans = max(ans, cnt_bits);
            }
        }

        return ans;
    }
};