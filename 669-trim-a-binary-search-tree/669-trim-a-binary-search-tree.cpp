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
    TreeNode* dfs(TreeNode* root,int lo,int hi){
        if(root==NULL) return NULL;
        
        if(root->val > hi){
            return dfs(root->left,lo,hi);
        }
        if(root->val < lo){
            return dfs(root->right,lo,hi);
        }
        root->left=dfs(root->left,lo,hi);
        root->right=dfs(root->right,lo,hi);
        
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // the left child if exists will always be less 
        // the right child if exists will always be more
        return dfs(root,low,high);
    }
};