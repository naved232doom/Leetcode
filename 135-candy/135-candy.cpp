class Solution {
public:
    int candy(vector<int>& arr) {
        // longest increasing subarray
        int n=int(arr.size());
        vector<int> pref(n+1,1);
        for(int i=1;i<n;++i){
            if(arr[i]>arr[i-1]){
               pref[i]=max(pref[i],pref[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;--i){
            if(arr[i]>arr[i+1]){
                pref[i]=max(pref[i],pref[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans+=pref[i];
        }
        return ans;
    }
};