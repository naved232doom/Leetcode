class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=(int)(nums.size());
        map<int,int> f;
        for(int i=0;i<n;++i) f[nums[i]]++;
        set<int> st(nums.begin(),nums.end());
        vector<array<int,2>> p;
        for(int v:st){
            p.push_back({f[v],v});
        }
        
        sort(p.rbegin(),p.rend());
        for(int i=0;i<k;++i) ans.push_back(p[i][1]);
        
        return ans;
    }
};