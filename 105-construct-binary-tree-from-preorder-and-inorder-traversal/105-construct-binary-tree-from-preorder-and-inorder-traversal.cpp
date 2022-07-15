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
    map<int,int> inorder_idx;
    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, int l_in, int r_in, int l_pre) {

        if (l_in > r_in or l_pre >= preorder.size()) return nullptr;

        int idx_root = -1;
        idx_root=inorder_idx[preorder[l_pre]];
        assert(idx_root != -1);
        TreeNode* root = new TreeNode(preorder[l_pre]);

        int cnt_left_subtree = idx_root - l_in + 1;

        root->left = dfs(preorder, inorder, l_in, idx_root - 1, l_pre + 1);
        root->right = dfs(preorder, inorder, idx_root + 1, r_in, l_pre + cnt_left_subtree);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        // bottom-line=> we get lengths of left and right subtree from inorder
        for(int i=0;i<inorder.size();++i){
            inorder_idx[inorder[i]]=i;
        }
        return dfs(preorder, inorder, 0, inorder.size(), 0);
    }
};