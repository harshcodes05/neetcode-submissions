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
        int low = 0, high = inorder.size()-1;
        TreeNode* root = new TreeNode(preorder[0]);
        int i;
        for(i = 0; i <high+1; i++) {
            if(inorder[i] == preorder[0]) break;
        }
        int idx = 1;
        dfs(root, preorder, inorder,idx,low,i-1,true);
        dfs(root, preorder, inorder, idx, i+1, high, false);
        return root;
    }
    void dfs(TreeNode* root, vector<int>& pre, vector<int>& in, int &idx, int low, int high, bool flag) {
        if(low>high) return;
        TreeNode* child = new TreeNode(pre[idx]);
        if(flag) root->left = child;
        else root->right = child;
        int i;
        for(i = low; i <= high; i++)
            if(in[i]==child->val)
                break;
        idx++;
        dfs(child, pre, in, idx, low, i-1,true);
        dfs(child, pre, in, idx, i+1, high, false);
    }
};
