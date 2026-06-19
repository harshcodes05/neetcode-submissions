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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int sum = dfs(root, res);
        return res;
    }
    int dfs(TreeNode* r, int& res) {
        if(!r) return 0;
        int l_path_sum = r->val + dfs(r->left, res);
        int r_path_sum = r-> val + dfs(r->right, res);
        res = max(res, max(r->val, max(l_path_sum+r_path_sum-r->val, max(l_path_sum, r_path_sum))));
        return max(r->val,max(l_path_sum, r_path_sum));
    }
};
