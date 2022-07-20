class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& W) {
        int nw = (int)(W.size());
        vector<set<pair<int, int>>> pos(26);
        int n = (int)(s.size());
        for (int i = 0; i < nw; ++i) {
            int c = W[i][0];
            pos[c - 'a'].insert({i, 0});
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            auto pos_tmp = pos[c];
            pos[c].clear();
            for (auto it : pos_tmp) {
                int pos_idx = it.second;
                int idx = it.first;
                int next_idx = pos_idx + 1;

                if (pos_idx + 1 >= (int)(W[idx].size())) {
                    ans++;
                    continue;
                }

                assert(next_idx < W[idx].size());
                int c_next = W[idx][next_idx] - 'a';

                pos[c_next].insert({idx, next_idx});
            }
        }

        return ans;
    }
};