class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n=(int)(arr.size());
        int ans=0;
        vector<int> idx(2);
        auto MX = *max_element(arr.begin(),arr.end());
        auto MN = *min_element(arr.begin(),arr.end());
        for(int i=0;i<n;++i)
        {
            if(arr[i]==MX) idx[1]=i;
            if(arr[i]==MN) idx[0]=i;
        }
        if(idx[0]>idx[1]) swap(idx[0],idx[1]);
        ans=idx[1]+1;
        ans=min(ans,n-idx[0]);
        ans=min(ans,idx[0]+1+n-idx[1]);
        return ans;
    }
};