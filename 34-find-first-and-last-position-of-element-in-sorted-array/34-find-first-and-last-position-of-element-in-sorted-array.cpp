class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (int)(nums.size());
        int lb = 0, rb = n;
        int left_most = n, right_most = 0;
        while (lb < rb) {
            int mid = (lb + rb) / 2;
            if (nums[mid] > target) {
                rb = mid;
            }
            else if (nums[mid] < target) {
                lb = mid + 1;
            }
            else {
                rb = mid;
                left_most = min(left_most, mid);
            }
        }
        lb = 0, rb = n;
        while (lb < rb) {
            int mid = (lb + rb) / 2;
            if (nums[mid] > target) {
                rb = mid;
            }
            else if (nums[mid] < target) {
                lb = mid + 1;
            }
            else {
                lb = mid + 1;
                right_most = max(right_most, mid);
            }
        }
        if (left_most == n) return { -1, -1};
        return {left_most, right_most};
    }
};