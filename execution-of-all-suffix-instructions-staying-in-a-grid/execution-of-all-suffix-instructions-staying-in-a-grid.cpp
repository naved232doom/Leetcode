class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int m = s.length();
        for (int i = 0; i < m; ++i)
        {
            vector<int> d(2);
            d[0] = startPos[0], d[1] = startPos[1];
            int cnt = 0;
            for (int j = i; j < m; ++j) {
                if (s[j] == 'U') d[0]--;
                if (s[j] == 'D') d[0]++;
                if (s[j] == 'L') d[1]--;
                if (s[j] == 'R') d[1]++;
                if (d[0] >= 0 && d[0] < n && d[1] >= 0 && d[1] < n) {
                    cnt++;
                }
                else break;
                //cout<<d[0]<<" "<<d[1]<<endl;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};