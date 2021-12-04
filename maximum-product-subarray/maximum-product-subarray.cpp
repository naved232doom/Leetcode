class Solution {
public:
    int maxProduct(vector<int>& nums) {
         // if we have even negative numbers -> good
            // if we have a zero then prod=1
            // we want to find the max as well as the min product here
            int n=(int)(nums.size());
        int P=1,ans=INT_MIN;
            
            for(int i=0;i<n;++i){
                    P*=nums[i];
                    ans=max(ans,P);
                    if(nums[i]==0) P=1;
            }
            P=1;
            for(int i=n-1;i;--i){
                    P*=nums[i];
                    ans=max(ans,P);
                    if(nums[i]==0) P=1;
            }
            return ans;
    }
};