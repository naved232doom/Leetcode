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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int l_in,int r_in,int l_post){
        if(l_in > r_in || l_post <0) return nullptr;
        TreeNode* cur = new TreeNode(postorder[l_post]);
        
        int idx=0;
        for(int i=l_in;i<=r_in;++i){
            if(inorder[i]==postorder[l_post]) idx=i;
        }
        
        int count_right=r_in-idx+1;
        cur->left=dfs(inorder,postorder,l_in,idx-1,l_post-count_right);
        cur->right=dfs(inorder,postorder,idx+1,r_in,l_post-1);
        return cur;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=(int)(inorder.size());
        return dfs(inorder,postorder,0,n-1,n-1);
        
    }
};