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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int idx = 0;
        return dfs(preorder, idx, 0, inorder.size() - 1, mp);
    }
    TreeNode* dfs(vector<int>& pre, int& idx, int low, int high, unordered_map<int, int>& mp) {
        if (low > high) return nullptr;
        int val = pre[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = mp[val];
        root->left = dfs(pre, idx, low, mid - 1, mp);
        root->right = dfs(pre, idx, mid + 1, high, mp);
        return root;
    }
};
