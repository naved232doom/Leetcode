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
    typedef long long ll;
    const ll INF=1e18;
    void dfs(TreeNode* root,ll x,ll y,bool &ok){
        if(root==nullptr) return;
        ll here=root->val;
        ll x_here=max(x,here);
        ll y_here=min(y,here);
        if(!(here<y && here>x)) ok=0;
        dfs(root->left,x,y_here,ok);
        dfs(root->right,x_here,y,ok);
    }
    bool isValidBST(TreeNode* root) {
        ll x=-INF,y=INF;
        bool ok=1;
        dfs(root,x,y,ok);
        return ok;
    }
};