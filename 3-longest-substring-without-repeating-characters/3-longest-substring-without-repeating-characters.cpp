class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        int lo=0,hi=0;
        vector<int> f((int)*max_element(s.begin(),s.end())+1,-1);
        while(lo<=hi && hi<n){
           
            // cout<<"hi :"<<hi<<endl;
            // cout<<"lo :"<<lo<<endl;
            bool ok=1;
            int c_here=s[hi];
            if(f[c_here]!=-1){
                int idx=f[c_here];
                while(lo<=idx && lo<=hi){
                    int c=s[lo];
                    f[c]=-1;
                    lo++;
                }
            }
            else{
                f[c_here]=hi;
                ans=max(ans,hi-lo+1);
                hi++;                
            }
        }
        return ans;
    }
};