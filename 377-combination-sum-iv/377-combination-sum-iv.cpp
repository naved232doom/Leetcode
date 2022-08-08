class Solution {
public:
    typedef unsigned long int ll;
    int combinationSum4(vector<int>& nums, int x) {
        int n=(int)(nums.size());
        
        sort(nums.begin(),nums.end());
        const int N=*max_element(nums.begin(),nums.end())+1;
        vector<ll> dp(x+1,0);
       dp[0]=1;
        for(int s=0;s<=x;++s){
         for(int i=0;i<n;++i){
                if(s-nums[i]>=0){
                    dp[s]+=dp[s-nums[i]];
                }         
            }
        }
        return dp[x];
    }
};