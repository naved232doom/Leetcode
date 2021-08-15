class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // -2 3 4 -2
        int ans=INT_MIN;
            int l=0,r=0;
            int n=(int)(nums.size());
            int cur=1;
            // 101 5 2 6 k= 100
            // l =1,r =0
            // 
            int maxhere=nums[0],minhere=nums[0];
            ans=max(ans,maxhere);
        for(int i=1;i<n;++i){
            if(nums[i]>=0){
                    maxhere=max(maxhere*nums[i],nums[i]);
                    minhere=min(minhere*nums[i],nums[i]);
            }
                else{   
                        int temp=maxhere;
                        maxhere=max(minhere*nums[i],nums[i]);
                        minhere=min(temp*nums[i],nums[i]);
                }
                ans=max(ans,maxhere);
        }   
            
            return ans;
    }
};