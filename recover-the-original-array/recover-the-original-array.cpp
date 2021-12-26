class Solution {
public:
    vector<int> recoverArray(vector<int>& arr) {
        int n = (int)(arr.size());
        sort(arr.begin(), arr.end());
        int smallest = arr[0];
        for (int i = 1; i < n; ++i) {
            int k_possible = arr[i] - smallest;
            //cout<<k_possible<<"\n";
            if (k_possible % 2 || k_possible == 0) continue;
            multiset<int> ms;
            for (int j = 0; j < n; ++j) ms.insert(arr[j]);
            vector<int> ans;
            for (int j = 0; j < n / 2; ++j) {
                assert(!ms.empty());
                auto small = *(ms.begin());
                auto it = ms.lower_bound(small + k_possible);
                if (it == ms.end()) break;
                ms.erase(ms.begin());
                if (*it == small + k_possible) {
                    ans.push_back(small + k_possible / 2);
                    ms.erase(it);
                }
                else break;
            }
            if ((int)(ans.size()) == n / 2) return ans;
        }
        return { -1};
    }
};