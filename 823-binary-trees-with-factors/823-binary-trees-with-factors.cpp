class Solution {
public:
    typedef long long ll;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=(int)(arr.size());
        vector<ll> dp(n,1);
        map<int,int> idx;
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=0;i<n;++i){
            idx[arr[i]]=i;
        }
        const int mod=1e9+7;
        for(int i=0;i<n;++i){
            dp[i]=1;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                int s=arr[j];
                if(arr[i]%s!=0 || idx.find(arr[i]/s)==idx.end()) continue;
                ll ans_here=0;
                // cout<<"arr[i] "<<arr[i]<<endl;
                // cout<<"s "<<s<<endl;
                // cout<<"dp[s] "<<dp[s]<<endl;
                // cout<<"dp[arr[i]/s] "<<dp[arr[i]/s]<<endl;
                ans_here=(dp[j]%mod*dp[idx[arr[i]/s]]%mod)%mod;
                //ans_here=max(ans_here,1ll);
                dp[i]+=ans_here;
                dp[i]%=mod;
                
            }
        }
        for(auto &it:dp){
            ans+=it;
           // cout<<it.first<<" "<<it.second<<endl;
            ans%=mod;
        }
        return ans;
    }
};