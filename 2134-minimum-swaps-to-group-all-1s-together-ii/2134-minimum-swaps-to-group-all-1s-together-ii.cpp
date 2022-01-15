class Solution {
      
public:
    int minSwaps(vector<int>& arr) {
       int n=(int)(arr.size());
            for(int i=0;i<n;++i) arr.push_back(arr[i]);
            int ans=1e9;
            int ans_here=0;
            for(int i=0;i<n;++i) if(arr[i]==0) ans_here++;
            int count_ones=n-ans_here;
            ans_here=0;
            for(int i=0;i<count_ones;++i) if(arr[i]==0) ans_here++;
            for(int i=count_ones;i<2*n;++i){
                    int left=i-count_ones;
                    if(arr[left]==0) ans_here--;
                    if(arr[i]==0) ans_here++;
                    ans=min(ans,ans_here);
            }
            return ans;
    }
};