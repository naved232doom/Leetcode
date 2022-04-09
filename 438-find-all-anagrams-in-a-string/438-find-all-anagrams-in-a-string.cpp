class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        vector<int> p_f(26),s_f(26);
        for(char c:p) p_f[c-'a']++;
        
        vector<int> ans;
        int np=p.length();
        
        for(int i=0;i<np;++i){
            s_f[s[i]-'a']++;
        }
        bool ok=1;
        if(s_f!=p_f) ok=0;
        if(ok){
                ans.push_back(0);
        }
        int ns=s.length();
        for(int i=np;i<ns;++i){
            int prev=s[i-np]-'a',here=s[i]-'a';
            s_f[prev]--;
            s_f[here]++;
             ok=1;
            for(int j=0;j<26;++j){
                if(s_f[j]!=p_f[j]){
                    ok=0;
                }
            }
            if(ok){
                ans.push_back(i-np+1);
            }
        }
        return ans;
    }
};