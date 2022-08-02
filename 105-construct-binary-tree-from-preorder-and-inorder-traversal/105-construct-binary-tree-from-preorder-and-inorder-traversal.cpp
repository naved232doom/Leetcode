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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int l_in,int r_in,int l_pre){
        if(l_in > r_in || l_pre>=preorder.size()) return nullptr;
        
        int node=preorder[l_pre];
        int node_idx;
        for(int i=l_in;i<=r_in;++i){
            if(node==inorder[i]) node_idx=i;
        }
        int left_count = node_idx-l_in+1;
        int right_count = (int)(inorder.size())- node_idx+1;
        
        TreeNode* cur=new TreeNode(preorder[l_pre]);
        
        cur->left=dfs(preorder,inorder,l_in,node_idx-1,l_pre+1);
        cur->right=dfs(preorder,inorder,node_idx+1,r_in,l_pre+left_count);
        return cur;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=(int)(preorder.size());
        return dfs(preorder,inorder,0,n-1,0);
    }
};