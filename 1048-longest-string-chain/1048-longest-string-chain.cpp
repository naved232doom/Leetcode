class Solution {
    int is_subs(string &a, string &b){
        int n=a.length(),m=b.length();
        int i=0,j=0;
        for(;i<n&&j<m;){
            if(a[i]==b[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        return i==n&&m==n+1;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b){
            return (int)a.length()< (int)b.length();
        });
        int n=(int)(words.size());
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(words[j].length()!=1+words[i].length()) continue;
                if(words[j].length()>1+words[i].length()) break;
                
                if(is_subs(words[i],words[j])){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};