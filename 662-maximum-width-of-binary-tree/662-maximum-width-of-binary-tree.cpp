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
typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // intended solution bfs on each level
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 1});
        ll ans = 0;
        while (!q.empty()) {
            int N = (int)(q.size());
            ll p = q.front().second;
            ll max_here = -1, min_here = 1e9;
            for (int i = 0; i < N; ++i) {
                auto cur = q.front();
                auto root_here = cur.first;
                //cout<<cur.second<<endl;
                q.pop();
                auto idx_here = cur.second - p;
                max_here = max(max_here, idx_here);
                min_here = min(min_here, idx_here);
                if (root_here->left) q.push({root_here->left, idx_here * 2 + 1});
                if (root_here->right) q.push({root_here->right, idx_here * 2 + 2});
            }
            ans = max(ans, max_here - min_here + 1);
        }
        return ans;
    }
};