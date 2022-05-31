class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // all numbers from 0 to exp(2,k+1)-1
        int n=(int)(s.length());
        const int MAX=(1<<(k+1));
        vector<int> f(MAX);
        
        for(int i=0,j=i+k-1;i<n&&j<n;++i,++j){
            int val_here=0;
            for(int l=0,p=j;l<k;++l,--p){
                if(s[p]=='1'){
                    val_here|=(1<<l);
                }
            }
            assert(val_here<(MAX));
            f[val_here]|=1;
        }
        int cnt= count(f.begin(),f.end(),1);
        //cout<<cnt<<endl;
        return cnt==(1<<k) ;
    }
};