/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    void dfs(TreeNode* o,TreeNode* c,TreeNode* target,TreeNode* &ans){
        if(o==NULL) return;
        if(o==target){
            ans=c;
        }
        dfs(o->left,c->left,target,ans);
        dfs(o->right,c->right,target,ans);
    }
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* target) {
        TreeNode* ans;
        
        dfs(o,c,target,ans);
        
        return ans;
    }
};