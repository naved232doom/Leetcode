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
    void inorder(TreeNode* root,vector<TreeNode*> &order){
        if(root==NULL) return;
        
        inorder(root->left,order);
        order.push_back(root);
        inorder(root->right,order);
        
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> order;
        inorder(root,order);
        vector<TreeNode*> unsorted;
        // 3 2 1
        // 1 2 3
        // 1 3 2 4
        // 1 2 3 4
        vector<int> nums;
        for(auto v:order){
            nums.push_back(v->val);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<(int)(order.size());++i){
            int val_here= order[i]->val;
            if(val_here!=nums[i]){
               // cout<<val_here<<endl;
                unsorted.push_back(order[i]);
            }
        }
        assert((int)unsorted.size()==2);
        swap(unsorted[0]->val,unsorted[1]->val);
    }
};