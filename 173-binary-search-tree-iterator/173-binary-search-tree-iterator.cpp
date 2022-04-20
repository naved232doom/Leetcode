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
class BSTIterator {
    private:
    TreeNode* prev=new TreeNode(-1);
    vector<int> vals;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        vals.push_back(root->val);
        dfs(root->right);
    }
    int idx=0;
    public:
    
    BSTIterator(TreeNode* root) {
       dfs(root);
        idx=0;
    }
    
    int next() {
       return vals[idx++];
    }
    
    bool hasNext() {
        return idx<(int)(vals.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */