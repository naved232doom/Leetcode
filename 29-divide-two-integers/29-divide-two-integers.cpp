class Solution {
    typedef long long int ll;
public:
    int divide(ll dividend, ll divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool neg=0;
        // if(dividend > (1ll<<31)-1) return ((1ll<<31)-1);
        // if(dividend < -(1ll<<31)) return (-(1ll<<31));
        if(dividend<0 && divisor>0) neg=1;
        if(dividend>0 && divisor<0) neg=1;
        dividend=(ll)abs(dividend);
        divisor=(ll)abs(divisor);
       // const int INF= dividend+1;
        ll ans=0; 
        while(dividend>=divisor){
             
            ll here=divisor,ans_here=1;
            while(here*2<=dividend){
                here*=2;
                ans_here*=2;
            }
            ans+=ans_here;
            dividend-=here;
         }   
        
        return (neg ? -ans:ans);
    }
};