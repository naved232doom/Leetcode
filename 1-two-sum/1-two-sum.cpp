class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = (int)(nums.size());
        vector<int> ans;
        //3 1 2 3 4 5 
        //
        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                
            }
        }
        return {};
    }
};