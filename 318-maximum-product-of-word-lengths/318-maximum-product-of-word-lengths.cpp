class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=(int)(words.size());
        if(n==1) return 0;
        vector<int> bits(n);
        for(int i=0;i<n;++i){
            for(char c:words[i]){
                bits[i]|=(1ll<<(c-'a'));
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if((bits[i]&bits[j])==0){
                ans=max(ans,(int)(words[i].length())*(int)(words[j].length()));
                }
            }
        }
        return ans;
    }
};