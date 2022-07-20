class Solution {
public:
    typedef long long ll;
        const int mod = (int)(1e9 + 7);
    ll nc2(ll x) {
        return (x * (x + 1)) / 2;
    }
    ll sub(ll x, ll y){
        return ((x-y)%mod+mod)%mod;
    }
    ll mult(ll x,ll y){
        return (x%mod*y%mod)%mod;
    }
    ll add(ll x,ll y){
        return (x+y)%mod;
    }
    int maxProfit(vector<int>& arr, int x) {
        // 1 1 2 2 2 4 5 6
        int n = (int)(arr.size());
        ll ans = 0;
        ll N = x;
        sort(arr.rbegin(), arr.rend());
        arr.push_back(0);
        n = (int)(arr.size());
        for (int i = 1; i < n; ++i) {
            int len = i;
            ll balls_left = (ll)(len) * (arr[i - 1] - arr[i]);
            ll here = nc2(arr[i - 1]) - nc2(arr[i]);
            if (N >= balls_left) {
                N -= balls_left;
                ll tot = mult(here,len);
                ans=add(ans,tot);
               
            }
            else {
                ll take_full = N / len;
                ll take_rem = N % len;
                ll left = arr[i - 1] - take_full;
                ll subs = sub(nc2(arr[i-1]),nc2(left));
                ans = add(ans,mult(subs,len));
                ans = add(ans,(mult(left,take_rem)));
                N = 0;
            }
        }
      
        return ans;
    }
};