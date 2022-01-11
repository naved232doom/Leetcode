class Solution {
private:
    int find_left(vector<int> &nums, int target) {
        int n = (int)(nums.size());
        int lb = 0, rb = n;
        int left_most = n;
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
        return (left_most == n ? -1 : left_most);
    }
    int find_right(vector<int> &nums, int target) {
        int n = (int)(nums.size());
        int lb = 0, rb = n;
        int right_most = -1;
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
        return (right_most == -1 ? -1 : right_most);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_most = find_left(nums, target), right_most = find_right(nums, target);
        return {left_most, right_most};
    }
};