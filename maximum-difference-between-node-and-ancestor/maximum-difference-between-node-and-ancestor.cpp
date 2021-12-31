/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int min_value, int max_value, int &ans) {
        if (root == NULL) return;
        ans = max(ans, abs(root->val - max_value));
        ans = max(ans, abs(root->val - min_value));
        min_value = min(min_value, root->val);
        max_value = max(max_value, root->val);
        dfs(root->left, min_value, max_value, ans);
        dfs(root->right, min_value, max_value, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        // keep track of the min and max values
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
};