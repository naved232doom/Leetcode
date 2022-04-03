class Solution {
    private:
    bool is_palindrome(string s){
        int n=(int)(s.size());
        for(int i=0;i<n/2;++i){
            if(s[i]!=s[n-i-1]) return 0;
        }
        return 1;
    }
public:
    bool validPalindrome(string s) {
        int n=(int)(s.size());
        if(is_palindrome(s)) return 1;
        for(int l=0,r=n-1;l<r;++l,--r){
            if(s[l]==s[r]) continue;
    return (is_palindrome(s.substr(l+1,r-(l+1)+1))|| is_palindrome(s.substr(l,r-1-l+1)));
        }
        return 0;
    }
};