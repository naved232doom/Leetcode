class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // we care about the tallest person beyong which we cannot see
        vector<int> st;
        int n = (int)(heights.size());
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int cur = 0;
            while (!st.empty() && st.back() < heights[i]) {
                cur++;
                st.pop_back();
            }
            if (!st.empty()) cur++;
            ans[i] = cur;
            st.push_back(heights[i]);
        }

        return ans;
    }
};