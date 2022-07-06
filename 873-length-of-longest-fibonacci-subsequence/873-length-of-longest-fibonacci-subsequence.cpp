class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=(int)(arr.size());
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<n;++i) mp[arr[i]]=i;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                int here=arr[i]+arr[j];
                if(mp.find(here)==mp.end()) continue;
                int ans_here=2;
                int prev=arr[i];
                while(mp.find(here)!=mp.end()){
                    ans_here++;
                    int tmp_prev=prev;
                    prev=here;
                    here=here+tmp_prev;
                }
                ans=max(ans,ans_here);
            }
        }
        return ans;
    }
};