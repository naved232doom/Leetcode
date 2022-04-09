class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=(int)(nums.size());
        map<int,int> f;
        for(int i=0;i<n;++i) f[nums[i]]++;
        vector<int> v[n+1];
        for(auto e:f){
            v[e.second].push_back(e.first);
        }
        for(int i=n;i>=0&&((int)ans.size()<k);--i){
            while(!v[i].empty()&&((int)(ans.size())<k)){
                ans.push_back(v[i].back());
                v[i].pop_back();
            }
        }
        return ans;
    }
};