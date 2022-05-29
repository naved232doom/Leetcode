class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=(int)(words.size());
        int f[n][26];
        memset(f,0,sizeof f);
        for(int i=0;i<n;++i){
            for(char c:words[i]){
                f[i][c-'a']++;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int mx_here=0;
                for(int k=0;k<26;++k){
                    mx_here=max(mx_here,min(f[i][k],f[j][k]));
                }
                if(mx_here==0){
                    ans=max(ans,(int)words[i].length()*(int)words[j].length());
                }
            }
        }
        return ans;
    }
};