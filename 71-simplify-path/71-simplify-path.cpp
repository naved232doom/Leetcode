class Solution {
public:
    string simplifyPath(string s) {
            string ans="";
            s+="/";
            //cout<<s<<endl;
        int n=s.length();
            vector<string> words;
            string here="";
            for(int i=0;i<n;++i){
                    if(s[i]=='/'){
                    //cout<<here<<endl;
                            if(here==".."){
                                    if(!words.empty()) words.pop_back();
                                    here.clear();
                                    continue;
                            }
                            if(here=="."||here=="/"){
                                    here.clear();
                                    continue;
                            }
                            if(!here.empty())
                            words.push_back(here);
                            here.clear();
                    }
                    else{
                            here+=s[i];
                    }
            }
            ans+="/";
            for(auto w:words) {
                    if(w.empty()) continue;
                    ans+=w;
                        ans+='/';
            }
            if(ans.length()>1&&ans.back()=='/') ans.pop_back();
            return ans;
    }
};