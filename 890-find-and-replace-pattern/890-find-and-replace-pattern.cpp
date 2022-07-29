class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &w:words){
            map<char,char> mp,mp2;
            bool ok=1;
            cout<<w<<endl;
            for(int i=0;i<w.length();++i){
                if(mp.find(pattern[i])!=mp.end()){
                    // cout<<"w[i] "<<w[i]<<endl;
                    // cout<<"mp[w[i]] "<<mp[w[i]]<<endl;
                    if(mp[pattern[i]]!=w[i]) ok=0;
                }
                else {
                   if(mp2.find(w[i])!=mp2.end()){
                       ok=0;
                   }
                    mp[pattern[i]]=w[i];
                    mp2[w[i]]=pattern[i];
                }
            }
            
            if(ok){
                ans.push_back(w);
            }
        }
        
        return ans;
    }
};