class Solution {
public:
    typedef long long ll;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=(int)(arr.size());
        map<ll,ll> dp;
        sort(arr.begin(),arr.end());
        ll ans=0;
        const int mod=1e9+7;
        for(int i=0;i<n;++i){
            dp[arr[i]]=1;
        }
        for(int i=0;i<n;++i){
            for(int s=1;s*s<=arr[i];++s){
                if(arr[i]%s!=0) continue;
                ll ans_here=1;
                // cout<<"arr[i] "<<arr[i]<<endl;
                // cout<<"s "<<s<<endl;
                // cout<<"dp[s] "<<dp[s]<<endl;
                // cout<<"dp[arr[i]/s] "<<dp[arr[i]/s]<<endl;
                ans_here=(dp[s]%mod*dp[arr[i]/s]%mod)%mod;
                //ans_here=max(ans_here,1ll);
                dp[arr[i]]+=ans_here;
                dp[arr[i]]%=mod;
                if(s!=arr[i]/s){
                    dp[arr[i]]+=ans_here;
                    dp[arr[i]]%=mod;
                }
            }
        }
        for(auto &it:dp){
            ans+=it.second;
           // cout<<it.first<<" "<<it.second<<endl;
            ans%=mod;
        }
        return ans;
    }
};