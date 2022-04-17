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
    void dfs(TreeNode* root,TreeNode* &ans){
        if(root==NULL) return ;
        
        dfs(root->left,ans);
        // if(root->left){
        // ans->right=root->left;
        // ans=ans->right;
        // }
        ans->right=new TreeNode(root->val);
        ans=ans->right;
        dfs(root->right,ans);
        // if(root->right){
        // ans->right=root;
        // ans=ans->right;
        // }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans=new TreeNode(0);
        auto res=ans;
        dfs(root,ans);
        return res->right;
    }
};