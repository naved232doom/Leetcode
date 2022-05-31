class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // all numbers from 0 to exp(2,k+1)-1
        int n = (int)(s.length());
        if (n < k) return 0;
        const int MAX = (1 << (k + 1));
        unordered_set<int> f;
        int val_here = 0;
        for (int l = 0, p = l + k - 1; l < k; ++l, --p) {
            if (s[p] == '1') {
                val_here |= (1 << l);
            }
        }
        f.insert(val_here);
        for (int i = 1, j = i + k - 1; i < n && j < n; ++i, ++j) {
            int prev_idx = i - 1;
            val_here -= (s[prev_idx] == '1' ? (1 << (k - 1)) : 0);
            val_here *= 2;
            val_here += (s[j] == '1' ? 1 : 0);
            assert(val_here < (MAX));
            if (f.find(val_here) != f.end()) continue;
            f.insert(val_here);
        }
        int cnt = (int)(f.size());
        //cout<<cnt<<endl;
        return cnt == (1 << k) ;
    }
};