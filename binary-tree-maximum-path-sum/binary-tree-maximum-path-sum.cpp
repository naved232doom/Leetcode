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
                int left_ans=0,right_ans=0;
                left_ans=max(left_ans,dfs(root->left,ans));
                right_ans=max(right_ans,dfs(root->right,ans));
                int ans_here=left_ans+right_ans+root->val;
                ans=max(ans_here,ans);
                return max(left_ans+root->val,root->val+right_ans);
        }
        public:
    int maxPathSum(TreeNode* root) {
        // you can take either the left or the right nodes
            int ans=INT_MIN;
            
            dfs(root,ans);
            return ans;
    }
};