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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* r, int maxi) {
        if(!r) return 0;
        int c = 0;
        if(r->val >= maxi) c = 1;
        maxi = max(maxi, r->val);
        c += dfs(r->left, maxi);
        c += dfs(r->right, maxi);
        return c;
    }
};
