class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=(int)(arr.size());     
        int ans=0;
        vector<int> pref(1,0);
        vector<int> suf(n+1,0);
        for(int i=0;i<n;++i){
            pref.push_back(pref.back()+arr[i]);
            
        }
        for(int i=n-1;i>=0;--i){
            suf[i]=suf[i+1]+arr[i];
        }
        for(int i=0;i<=n;++i){
            int left=pref[i];
            int r=k-i;
            if(r<0) break;
            int rem=n-r;
            int ans_here=pref[i]+suf[rem];
            ans=max(ans,ans_here);
        }
        return ans;
    }
};