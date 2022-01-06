class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length(), nt = t.length();
        map<char, int> mp;
        for (char c : t) mp[c]++;

        int rem = nt;
        int min_len = INT_MAX, start_index = -1;
        for (int start = 0, ends = 0; ends < ns; ++ends) {
            mp[s[ends]]--;
            if (mp[s[ends]] >= 0) {
                rem--;
            }
            while (rem == 0) {
                if (ends - start + 1 < min_len) {
                    min_len = ends - start + 1;
                    start_index = start;
                }
                mp[s[start]]++;
                if (mp[s[start]] > 0) rem++;
                start++;
            }
        }
        if (min_len == INT_MAX) return "";
        string ans = s.substr(start_index, min_len);
        return ans;
    }
};