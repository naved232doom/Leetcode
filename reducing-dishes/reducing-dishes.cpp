class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        int n=(int)(a.size());
            sort(a.begin(),a.end());
            int ans=0;
            for(int i=n-1;i>=0;--i){
                    int cur=0;
                    for(int j=i,cnt=1;j<n;++j,++cnt){
                           cur+=(cnt)*(a[j]); 
                    }
                    ans=max(ans,cur);
            }
            return ans;
    }
};