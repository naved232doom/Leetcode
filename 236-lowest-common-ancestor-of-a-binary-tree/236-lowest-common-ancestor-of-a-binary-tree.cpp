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
public:
    vector<int> lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans,vector<int> present){
        
        if(root==nullptr) return {0,0};
        // p.val==root->val => present[0]=1;
        auto left=lca(root->left,p,q,ans,present);
        auto right=lca(root->right,p,q,ans,present);
        for(int i=0;i<2;++i){
            present[i]|=left[i];
            present[i]|=right[i];
        }
        // if(root->val==3){
        //     cout<<present[0]<<" "<<present[1]<<endl;
        // }
         if(p->val==root->val) present[0]=1;
        if(q->val==root->val) present[1]=1;
        if(present[0] && present[1] && !ans) ans=root;
        return present;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> present(2);
        TreeNode* ans=nullptr;
        lca(root,p,q,ans,present);
        return ans;
    }
};