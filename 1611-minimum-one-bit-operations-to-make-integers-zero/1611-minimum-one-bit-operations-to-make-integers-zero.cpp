class Solution {
public:
    int minimumOneBitOperations(int n) {
     // 110010000
     // 110010110  
        // 1110
        // 0110
        if(n<=1) return n;
        int ans=0;
        int hb=0;
        for(int i=0;i<30;++i){
            if(n&(1<<i)){
                hb=i;
            }
        }
        
        return (1<<(hb+1))-1 - minimumOneBitOperations(n-(1<<(hb)));
    }
};