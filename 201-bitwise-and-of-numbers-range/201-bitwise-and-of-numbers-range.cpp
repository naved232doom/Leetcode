class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=32;i>=0;--i){
            if((right& (1ll<<i))&&!(left&(1ll<<i))){
                break;
            }
            if((right&(1ll<<i))&&(left&(1ll<<i))){
                ans+= (1ll<<i);
            }
        }
        return ans;
    }
};