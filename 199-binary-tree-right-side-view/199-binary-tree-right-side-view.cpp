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
    void dfs(TreeNode *root,vector<int> &ans,int lvl=1){
        if(root==NULL) return;
        if(int(ans.size()) < lvl){
            ans.push_back(root->val);
        }
        dfs(root->right,ans,lvl+1);
        dfs(root->left,ans,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};