class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=(int)(nums.size());
        for(int i=0;i<n;++i){
            int idx=abs(nums[i])-1;
            if(nums[idx]<0){
                return abs(nums[i]);
            }
            else{
                nums[idx]=-nums[idx];
            }
        }
        return 0;
    }
};