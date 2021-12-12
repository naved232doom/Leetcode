class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 1. find the overall sum of all elements
        // if sum is not even then return 0
            // we do knapsack ont the remaining elements and see is we get sum/2
            int sum=0;
            for(int v:nums) sum+=v;
            if(sum%2) return 0;
            vector<int> dp(sum+1);
            int n=(int)(nums.size());
            dp[0]=1;
            for(int i=0;i<n;++i)
            for(int s=sum;s>=0;--s){
                    if(s-nums[i]>=0){
                            dp[s]|=dp[s-nums[i]];
                    }
            }
            return dp[sum/2];
    }
};