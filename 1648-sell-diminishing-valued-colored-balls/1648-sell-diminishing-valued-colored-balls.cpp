class Solution {
    typedef long long ll;
public:
    ll nc2(ll x){
        return (x*(x+1))/2;
    }
    int maxProfit(vector<int>& arr, int x) {
        // 1 1 2 2 2 4 5 6
        int n=(int)(arr.size());
        ll ans=0;
        ll N=x;
        sort(arr.rbegin(),arr.rend());
        arr.push_back(0);
        const int mod=(int)(1e9+7);
        n=(int)(arr.size());
        for(int i=1;i<n;++i){
            int len=i;
            ll balls_left=(ll)(len)*(arr[i-1]-arr[i]);
            ll here= nc2(arr[i-1])-nc2(arr[i]);
            if(N>=balls_left){
                N-=balls_left;
                ll tot= (here%mod *len%mod)%mod;
                ans+=tot;
                ans%=mod;
            }
            else{
                ll take_full=N/len;
            ll take_rem= N%len;
            ll left= arr[i-1]-take_full;
                ll sub=nc2(arr[i-1])-nc2(left);
                sub%=mod;
                sub+=mod;sub%=mod;
            ans+=((sub%mod)*len%mod)%mod;
            ans%=mod;
            ans+=((left)%mod*take_rem%mod);
            ans%=mod;
                N=0;
            }
        }
        if(N){
            // mid*n
            ll take_full=N/n;
            ll take_rem= N%n;
            ll left= arr.back()-take_full;
            ans+=(nc2(arr.back())%mod-nc2(left)%mod)*n;
            ans+=mod;ans%=mod;
            ans+=(left)*take_rem;
            ans%=mod;
        }
        // 5, 2
        // here= 9 , balls_left=2
        // ans=9
        // N=4; take_full= 4/2=2,take_rem=0, left=3-2=1, ans+=(6-1)*2
        return ans;
    }
};