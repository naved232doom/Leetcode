class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> fp(10);
        int t = n;
        while (t) {
            fp[t % 10]++;
            t /= 10;
        }
        for (int i = 0; i < 31; ++i) {
            int here = (1 << i);
            vector<int> fr(10);
            int t = here;
            while (t) {
                fr[t % 10]++;
                t /= 10;
            }
            bool bad = 0;
            for (int j = 0; j < 10; ++j) {
                if (fr[j] == fp[j]) continue;
                bad = 1;
            }
            if (!bad) return 1;
        }
        return 0;
    }
};