class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> ms;
        int n = (int)(nums.size());
        for (int i = 0; i < k; ++i) ms.insert(nums[i]);
        vector<int> ans;
        for (int i = 0; i + k < n; ++i) {
            ans.push_back(*(ms.begin()));
            ms.erase(ms.find(nums[i]));
            ms.insert(nums[i + k]);
        }
        ans.push_back(*(ms.begin()));
        return ans;
    }
};