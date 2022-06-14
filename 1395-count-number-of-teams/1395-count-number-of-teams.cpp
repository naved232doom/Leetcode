class Solution {
public:
    struct bit {
        int n;
        vector<long long> a;

        void init(int s) {
            a = vector<long long>(s + 1, 0);
            n = s;
        }

        void add(int loc, long long x) {
            if (loc <= 0) return;
            while (loc <= n) {
                a[loc] += x;
                loc += loc & (-loc);
            }
        }

        long long query(int loc) {
            long long sum = 0;
            while (loc > 0) {
                sum += a[loc];
                loc -= loc & (-loc);
            }
            return sum;
        }
    };

    void coordinate_compression(vector<int> &a) {
        auto d = a;
        int n = (int)(d.size());
        sort(d.begin(), d.end());
        d.resize(unique(d.begin(), d.end()) - d.begin());

        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
        }
    }
    int solve(vector<int> &arr) {
        bit bit;
        int N = *(max_element(arr.begin(),arr.end()))+1;
        int n=(int)(arr.size());
        bit.init(N + 1);
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = bit.query(N + 1) - bit.query(arr[i]);
            bit.add(arr[i], 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) continue;
                ans += dp[j];
            }
        }
        return ans;
    }
    int numTeams(vector<int>& arr) {
        int ans = 0;
        //coordinate_compression(arr);
        ans += solve(arr);
        reverse(arr.begin(), arr.end());
        ans += solve(arr);
        // 2 5 3 4 1
        // 1 4 3 5 2
        return ans;
    }
};