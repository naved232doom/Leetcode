class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> invalids;
        int len = s.length();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                invalids.emplace_back(i);
            }
            else {
                if (!invalids.empty() && s[invalids.back()] == '(') {
                    invalids.pop_back();
                }
                else {
                    invalids.emplace_back(i);
                }
            }
        }
        int R = len;
        while (!invalids.empty()) {
            int len_here = R - invalids.back() - 1;
            ans = max(ans, len_here);
            R = min(R, invalids.back());
            invalids.pop_back();
        }
        ans = max(ans, R);
        return ans;
    }
};