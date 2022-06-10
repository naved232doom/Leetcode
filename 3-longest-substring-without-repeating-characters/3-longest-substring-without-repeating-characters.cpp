class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=(int)(s.length());
        if(n<=1) return n;
        //return n;
        int ans=1;
        const int MAX=150;
        vector<int> f(MAX,-1);
        for(int i=0;i<n;++i){
            int c_here=s[i];
            //cout<<c_here<<endl;
            if(f[c_here]!=-1){
                int idx=f[c_here];
                f.assign(MAX,-1);
                for(int j=idx+1;j<=i;++j){
                    int c2=s[j];
                    f[c2]=j;
                }
            }
            else{
                f[c_here]=i;
            }
            int ans_here=0;
            for(int j=0;j<MAX;++j){
                if(f[j]==-1) continue;
                ans_here++;
            }
            ans=max(ans,ans_here);
        }
        
        return ans;
    }
};