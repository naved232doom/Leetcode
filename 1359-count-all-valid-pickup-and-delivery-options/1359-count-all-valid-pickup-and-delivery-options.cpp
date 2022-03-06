class Solution {
        typedef long long ll;
        const int mod=1e9+7;
public:
    int countOrders(int n) {
        ll ans=1;
        if(n==1) return ans;    
            for(int i=2;i<=n;++i){
                    ll s=(i-1)*2+1;
                    ans=ans*(s*(s+1))/2;        
                        ans%=mod;
            }
            
            return ans;
    }
};