class Solution {
public:
    int maxPower(string s) {
        int ans=0;
            int cur=1;
            int n=s.length();
            for(int i=1;i<s.length();++i){
                    if(s[i]==s[i-1]){
                       cur++;     
                       ans=max(ans,cur);     
                    }
                    else{
                            cur=1;
                    }
            }
            ans=max(ans,cur);
            return ans;
    }
};