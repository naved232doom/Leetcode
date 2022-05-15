class Solution {
public:
    int largestVariance(string s) {
        int n=(int)(s.length());
        set<char> st(s.begin(),s.end());
        int ans=0;
        for(char a:st){
            for(char b:st){
                int var_here=0;
                bool a_pres=0,b_pres=0;
                for(int i=0;i<n;++i){
                    if(s[i]!=a&&s[i]!=b) continue;
                    if(s[i]==b){
                        var_here++;
                        b_pres=1;
                    }
                    else if(s[i]==a){
                        var_here--;
                        a_pres=1;
                    }
                    if(b_pres&&a_pres){
                        ans=max(ans,var_here);
                    }
                    if(var_here<0){
                        b_pres=a_pres=0;
                        var_here=0;
                    }
                    
                }
            }
        }
        reverse(s.begin(),s.end());
        for(char a:st){
            for(char b:st){
                int var_here=0;
                bool a_pres=0,b_pres=0;
                for(int i=0;i<n;++i){
                    if(s[i]!=a&&s[i]!=b) continue;
                    if(s[i]==b){
                        var_here++;
                        b_pres=1;
                    }
                    else if(s[i]==a){
                        var_here--;
                        a_pres=1;
                    }
                    if(b_pres&&a_pres){
                        ans=max(ans,var_here);
                    }
                    if(var_here<0){
                        b_pres=a_pres=0;
                        var_here=0;
                    }
                    
                }
            }
        }
        return ans;
    }
};