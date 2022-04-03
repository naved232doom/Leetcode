class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=(int)(nums.size());
        int lo=0,hi=n-1;
        while(lo< hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi]){
                lo=mid+1;
            }
            else hi=mid;
        }
        return nums[lo];
    }
};