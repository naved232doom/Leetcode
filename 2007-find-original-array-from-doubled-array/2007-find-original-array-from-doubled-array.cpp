class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        // 1 2 3 6 
        sort(arr.begin(),arr.end());
        int mx=*max_element(arr.begin(),arr.end());
        mx++;
        vector<int> f(mx);
        int n=(int)(arr.size());
        if(n%2) return {};
        vector<int> ans;
        for(auto &v:arr) f[v]++;
        for(int i=n-1;i>=0;--i){
            auto here=arr[i];
            if(!f[here] || here%2) continue;
            f[here]--;
            auto need= here/2;
            if(f[need]){
                f[need]--;
                ans.push_back(need);
            }
        }
        if((int)(ans.size())!=n/2) return {};
        return ans;
    }
};