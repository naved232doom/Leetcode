class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
           int maxc=0,ends=0,maxnow=0;
            int i=0;
            int n= (int)(nums.size());
            if(n==1) return 0;
            for(;i<n;){
                    //cout<<i<<" "<<maxc<<endl;
                    maxnow=0;
                    
                   for(;i<=maxc;++i){
                           maxnow=max(maxnow,nums[i]+i);
                   }
                    //cout<<"i: "<<i<<endl;
                    ans++;
                    if(maxnow>=n-1) {
                            return ans;
                    }
                    
                    
                    maxc=max(maxnow,maxc);
            }
                
            
            return ans;
    }
};