class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        int n=(int)(nums.size());
            for(int i=1;i<n;++i) ans^=nums[i];
            return ans;
    }
};