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
    TreeNode* dfs(vector<int> &inorder, vector<int> &postorder, int l_inorder, int r_inorder, int l_postorder) {
        if (l_inorder > r_inorder or l_postorder >= postorder.size() or l_postorder < 0 ) return NULL;

        TreeNode* node = new TreeNode(postorder[l_postorder]);

        int idx = -1;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == postorder[l_postorder]) idx = i;
        }
        int left_cnt = idx - l_inorder + 1;
        int right_cnt = r_inorder - idx + 1;
        node->left = dfs(inorder, postorder, l_inorder, idx - 1, l_postorder - right_cnt);
        node->right = dfs(inorder, postorder, idx + 1, r_inorder, l_postorder-1);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};