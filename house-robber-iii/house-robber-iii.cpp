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
        map<TreeNode*,int> dp;
        map<TreeNode*,TreeNode*> childLeft,childRight;
        void dfs(TreeNode* root){
                if(root==NULL) return ;
                
                childLeft[root]=root->left;
                childRight[root]=root->right;
                dfs(root->left);
                dfs(root->right);
dp[root]=max(dp[root],root->val+dp[childLeft[root->left]]+dp[childRight[root->left]]+dp[childRight[root->right]]+dp[childLeft[root->right]]);
                dp[root]=max(dp[root],dp[childLeft[root]]+dp[childRight[root]]);
        }
    int rob(TreeNode* root) {
            childLeft[NULL]=NULL;
            childRight[NULL]=NULL;
            dp[NULL]=0;
            dfs(root);
            return dp[root];
        
    }
};