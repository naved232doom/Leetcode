class Solution {
public:
        typedef long long ll;
    int nthMagicalNumber(ll n, int a, int b) {
        const int mod=1e9+7;
            ll lb=1,rb=1e18;
                    ll G=__gcd(a,b);
                        ll L=(a*b)/G;
            ll ans=-1;
            while(lb<rb){
                   ll mid=(lb+rb)/2;
                ll k= mid/a+mid/b-mid/L;
                    //cout<<mid<<" "<<k<<endl;
                    if(k<n){
                            lb=mid+1;
                    }
                    else if(k>=n){
                            rb=mid;
                    }
                   
            }
            while(lb%a&&lb%b){
                    lb--;
            }
            return lb%mod;
    }
};