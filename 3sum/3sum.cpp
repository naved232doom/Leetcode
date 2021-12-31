class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
            int n=(int)(nums.size());
            sort(nums.begin(),nums.end());
           for(int i=0;i<n;++i){
                     int L=i+1,R=n-1;
                   while(L<R&&L<n&&R<n&&R>=0){
                           int sum_here=nums[L]+nums[i]+nums[R];
                           if(sum_here==0){
                                   ans.push_back({nums[i],nums[L],nums[R]});
                                   while(L+1<=R&&nums[L+1]==nums[L]) L++;
                                   L++;
                                   R--;
                           }
                           else if(sum_here>0){
                                   R--;
                           }
                           else {
                                   L++;
                           }
                   }
                   
                   while(i+1<n&&nums[i+1]==nums[i]) i++;
           }
            
            return ans;
    }
};