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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> tree;
        queue<TreeNode*> q;
        q.push(root);
        int j = 0;
        while(!q.empty()) {
            tree.resize(tree.size()+1);
            for(int i = q.size(); i > 0; i--) {
                TreeNode* p = q.front();
                q.pop();
                tree[j].push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            j++;
        }
        return tree;
    }
};
