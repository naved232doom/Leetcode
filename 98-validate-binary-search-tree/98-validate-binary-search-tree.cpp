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
    typedef long long ll;
    const ll inf= 1e18;
    private:
    bool dfs(TreeNode* root,ll hi,ll lo){
        if(root==NULL) return 1;
        if(root->val >= hi || root->val <=lo) return 0;
        if(!dfs(root->left,min(hi,(ll)root->val),lo)) return 0;
        if(!dfs(root->right,hi,max(lo,(ll)root->val))) return 0;
        
        return 1;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,inf,-inf);
    }
};