class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
            int l=0,r=0;
            int n=(int)(nums.size());
            int cur=1;
            // 101 5 2 6 k= 100
            // l =1,r =0
            // 
            while(l<n&&r<n){
                    assert(l<n&&r<n);
                    cur=cur*nums[r];
                while(l<=r&&cur>=k&&l<n){
                        cur/=nums[l++];
                        }
                          
                 ans+=r-l+1;
                    r++;
            }
            
            return ans;
         
    }
};