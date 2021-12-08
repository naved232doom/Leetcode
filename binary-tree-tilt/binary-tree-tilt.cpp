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
        int dfs(TreeNode* root,int &ans){
                if(root==NULL) return 0;
                int lSum=0,rSum=0;
                if(root->left) lSum=dfs(root->left,ans);
                if(root->right) rSum=dfs(root->right,ans);
                ans+=abs(lSum-rSum);
                return lSum+rSum+root->val;
        }
public:
    int findTilt(TreeNode* root) {
        int ans=0;
            dfs(root,ans);
            return ans;
    }
};