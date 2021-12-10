class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        int n=(int)(a.size());
            sort(a.begin(),a.end());
            int ans=0;
            int cnt=0,prefSum=0;
            for(int i=0;i<n;++i){
                   cnt+=(i+1)*a[i];
                    prefSum+=a[i];
            }
            for(int i=0;i<n;++i){
                   ans=max(ans,cnt); 
                   cnt-=prefSum;
                    ans=max(ans,cnt);
                    prefSum-=a[i];
            }
            return ans;
    }
};