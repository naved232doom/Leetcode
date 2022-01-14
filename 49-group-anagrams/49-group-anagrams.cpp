class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // O(len*log(len)*n+n)
        int n = (strs.size());
        map<string, vector<int>> bin_string;
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            string bin_here = "";
            vector<int> f(26);
                //cout<<strs[i]<<endl;
            for (char c : strs[i]) f[c - 'a']++;
            for (int j = 0; j < 26; ++j) {
                bin_here += to_string(f[j])+(char)('a'+j);
                   // cout<<f[j]<<endl;
            }
            //cout<<bin_here<<"\n";
            bin_string[bin_here].push_back(i);
        }
        for (auto it : bin_string) {
            vector<string> ans_here;
            //cout<<it.first<<endl;
            for (auto indexes : (it.second)) {
                //cout<<indexes<<endl;
                ans_here.push_back(strs[indexes]);
            }
            ans.push_back(ans_here);
        }
        return ans;
    }
};