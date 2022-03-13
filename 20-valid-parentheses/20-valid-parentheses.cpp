class Solution {
public:
    bool isValid(string s) {
        int n=(int)(s.length());
            vector<char> st;
            bool bad=0;
            for(int i=0;i<n;++i){
                    if(s[i]=='('||s[i]=='['||s[i]=='{') st.push_back(s[i]);
                    else{
                            if(st.empty()) return 0;
                           char opening;
                            if(s[i]==')') opening='(';
                            if(s[i]==']') opening='[';
                            if(s[i]=='}') opening='{';
                            if(st.back()!=opening) return 0;
                            st.pop_back();
                    }
            }
            
            if(bad|| !st.empty()) return 0;
            return 1;
    }
};