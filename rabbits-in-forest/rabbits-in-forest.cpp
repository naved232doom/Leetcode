class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
            vector<int> f(1005);
            for(int v:answers) f[v]++;
            for(int i=0;i<f[0];++i) ans++;
            for(int i=1;i<1005;++i){
                    int k=i+1;
                    int rem=f[i]%k;
                    ans+=(f[i]/k)*k;
                    if(rem)
                    ans+=k;
            }
            return ans;
                    
    }
};