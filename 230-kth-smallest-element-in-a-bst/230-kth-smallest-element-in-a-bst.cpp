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
    void dfs(TreeNode* root,int &l,int &k,int &ans){
       
        if(root==NULL||ans!=-1) return;
        dfs(root->left,l,k,ans);
        l++;
        if(l==k){
            ans=root->val;
        }
        dfs(root->right,l,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int l=0;
        int ans=-1;
        dfs(root,l,k,ans);
        return ans;
    }
};