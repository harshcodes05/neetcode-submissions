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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (q.size() > 0) {
            for (int i = q.size(); i > 0; i--) {
                TreeNode* n = q.front();
                q.pop();
                s += (n != nullptr) ? to_string(n->val)+',' : "N,";
                if (n) {
                    q.push(n->left);
                    q.push(n->right);
                }
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str != "N") {
                TreeNode* ln = new TreeNode(stoi(str));
                node->left = ln;
                q.push(ln); 
            } 

            getline(s,str,',');
            if(str != "N") {
                TreeNode* rn = new TreeNode(stoi(str));
                node->right = rn;
                q.push(rn); 
            } 
        }
        return root;
    }
};
