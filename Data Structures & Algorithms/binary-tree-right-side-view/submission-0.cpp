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
    vector<int> res = {};
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* r, int d) {
        if(!r) return;
        if(d == res.size()) res.push_back(r->val);
        dfs(r->right, d+1);
        dfs(r->left, d+1);
    }
};
