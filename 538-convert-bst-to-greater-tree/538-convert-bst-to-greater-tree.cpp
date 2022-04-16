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
    void dfs(TreeNode* root,vector<int> &order){
        if(root==NULL) return;
        
        dfs(root->left,order);
        order.push_back(root->val);
        dfs(root->right,order);
    }
    void dfs2(TreeNode* root,map<int,int> &pref){
        if(root==NULL) return;
        
        root->val=pref[root->val];
        dfs2(root->left,pref);
        dfs2(root->right,pref);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> order;
        dfs(root,order);
        // for(int v:order) cout<<v<<" ";
        // cout<<endl;
        // 0 1 2 3 4 5 6 7 8
        map<int,int> pref;
        int n=(int)(order.size());
        for(int i=n-1;i>=0;--i){
            int here=order[i];
            if(i+1<n){
                order[i]+=order[i+1];
            }
            pref[here]=order[i];
            //cout<<here<<" "<<pref[here]<<endl;
        }
        dfs2(root,pref);
        return root;
    }
};