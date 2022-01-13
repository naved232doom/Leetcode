class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)(nums.size());
        int left, mid, right;
        left = mid = 0;
        right = n - 1;
        // 2  0 2 1 1 0
        //L,M          H
        // 0  0 1 1 2 2
        //    L  H,M
        //
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[left]);
                mid++;
                left++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[right]);
                right--;
            }
            else mid++;

        }
    }
};