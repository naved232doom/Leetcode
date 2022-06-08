class Solution {
public:
    int removePalindromeSub(string s) {
        bool ok=1;
        int n=s.length();
        for(int i=0;i<s.length()/2;++i){
            if(s[i]!=s[n-i-1]) ok=0;
        }
        return (ok ? 1:2);
    }
};