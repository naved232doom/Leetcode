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
    void dfs(TreeNode* root,vector<int> &d,int lvl=1){
        if((int)(d.size())<lvl){
            d.push_back(0);
        }
        d[lvl-1]+=root->val;
        
        if(root->left) dfs(root->left,d,lvl+1);
        if(root->right) dfs(root->right,d,lvl+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<int> d;
        dfs(root,d);
        return d.back();
    }
};