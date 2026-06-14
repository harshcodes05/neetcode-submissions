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
    int caclH(TreeNode* root, bool &res) {
        if(!root) return 0;
        int l = caclH(root->left,res);
        int r = caclH(root->right,res);
        if(abs(r-l)>1) res = false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        int h = caclH(root,res);
        return res;
    }
};
