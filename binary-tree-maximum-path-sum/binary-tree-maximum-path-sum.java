/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
  int ans = Integer.MIN_VALUE;
  public int maxPathSum(TreeNode root) {
    dfs(root);
    return ans;
  }
  int dfs(TreeNode root) {
    if (root == null) return 0;
    int left_ans = 0, right_ans = 0;
    left_ans = Math.max(dfs(root.left), left_ans);
    right_ans = Math.max(dfs(root.right), right_ans);
    int ans_node = left_ans + right_ans + root.val;
    ans = Math.max(ans, ans_node);
    return Math.max(left_ans + root.val, right_ans + root.val);
  }
}