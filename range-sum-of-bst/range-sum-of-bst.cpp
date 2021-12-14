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
        bool inRange(int val,int low,int high){
                return val>=low&&val<=high;
        }
        void dfs(TreeNode* root,int low,int high,int &ans){
                
                if(root==NULL) return;
                if(inRange(root->val,low,high)){
                        ans+=root->val;
                }
                if(root->left) dfs(root->left,low,high,ans);
                if(root->right) dfs(root->right,low,high,ans);
        }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
            dfs(root,low,high,ans);
        return ans;
    }
};