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
private:
    void dfs(TreeNode* root, TreeNode* &ans) {
        if (root == NULL) return ;

        dfs(root->right, ans);
        dfs(root->left, ans);
        root->right = ans;
        root->left = NULL;
        ans = root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* ans = NULL;
        dfs(root, ans);

    }
};