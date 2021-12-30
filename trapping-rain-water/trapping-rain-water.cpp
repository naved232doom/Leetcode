class Solution {
public:
    int trap(vector<int>& height) {
        int n=(int)(height.size());
            vector<int> pref(n+1),suf(n+2);
            for(int i=0;i<n;++i) pref[i+1]=max(pref[i],height[i]);
            for(int i=n-1;i>=0;--i){
                    suf[i+1]=max(suf[i+2],height[i]);
            }
            int ans=0;
            // 1 2 3 4 5
            for(int i=0;i<n;++i){
                    int pref_max=pref[i];
                    int suf_max=suf[i+2];
                    int ht_here=height[i];
                    if(pref_max<=ht_here||suf_max<=ht_here) continue;
                    int water_here=min(suf_max,pref_max);
                    ans+=water_here-height[i];
            }
        return ans;
    }

};