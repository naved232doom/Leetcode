class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=(int)(nums.size());
        sort(nums.begin(),nums.end());
        // -1,0,1,2,-1,-4
        // -4 -1 -1 0 1 2
        // -4 
        
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            int l=i+1,r=n-1;
            while(l<r){
                int sum_here=nums[i]+nums[l]+nums[r];
                if(sum_here==0){
                    vector<int> ans_here={nums[i],nums[l],nums[r]};
                    ans.push_back(ans_here);
                    while(l<r&&nums[l]==ans_here[1]) l++;
                }
                else if(sum_here<0){
                    l++;
                }
                else{
                    r--;
                }
            }
            int v_here=nums[i];
            while(i+1<n&&nums[i+1]==v_here){
                i++;
            }
        }
        return ans;
    }
};