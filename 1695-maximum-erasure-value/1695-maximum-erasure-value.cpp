class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int n=(int)(arr.size());
        const int INF=(int)(1e9+5);
        int ans=-INF;
        int S=0;
        const int MX=1e4+5;
        vector<int> f(MX,-1);
        for(int i=0,j=0;i<n;++i){
            if(f[arr[i]]!=-1){
                int idx=f[arr[i]];
                for(int k=j;k<idx;++k) {
                    S-=arr[k];
                    f[arr[k]]=-1;
                }
                f[arr[i]]=i;
                j=idx+1;
            }
            else{
                S+=arr[i];
                f[arr[i]]=i;
            }
                ans=max(ans,S);
        }
        return ans;
    }
};