class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
            
        int n = nums.length;
        int[] left_max = new int[n + 1];
        int [] right_max = new int[n + 1];
        int n_min = -100000;
        for (int i = 0; i <= n; ++i) {
            left_max[i] = n_min;
            right_max[i] = n_min;
        }
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            left_max[i] = Math.max(left_max[i], nums[i]);
            if (i % k != 0) {
                left_max[i] = Math.max(left_max[i], left_max[i - 1]);
            }
            right_max[j] = Math.max(right_max[j], nums[j]);
            if (j % k != k - 1 && j + 1 < n) {
                right_max[j] = Math.max(right_max[j], right_max[j + 1]);
            }

        }

        int[] ans = new int[n - k + 1];
        for (int i = 0; i+k-1 < n; ++i) {
                ans[i]=Math.max(right_max[i],left_max[i+k-1]);
        }
            return ans;
    }
}