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
    // 0 1 2
    // 1 => no camera
    // 2 => has camera
    // 0 => not needed 
    int dfs(TreeNode* root, int &ans) {
        if (root == NULL) return 0;

        int ans_left = dfs(root->left, ans);
        int ans_right = dfs(root->right, ans);
        if (ans_left == 1 || ans_right == 1) {
            ans++;
            return 2;
        }
        else if (ans_left == 2 || ans_right == 2) {
            return 0;
        }
        else {
            return 1;
        }
       
    }
    int minCameraCover(TreeNode* root) {
        int len = 0;
        TreeNode* dummy = new TreeNode(-1);
        if (root->left == NULL && root->right == NULL) return 1;
        int ans = 0;
        if(dfs(root, ans) == 1) ans++;
        return ans;
    }
};