/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> exist;
        Node* root = new Node(node->val);
        queue<pair<Node*, Node*>> q;
        q.push(make_pair(node, root));
        exist[node->val] = root;
        int vis[101] = {0};
        vis[root->val] = 1;
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (auto it : a->neighbors) {
                Node* adj;
                if (exist.count(it->val))
                    adj = exist[it->val];
                else {
                    adj = new Node(it->val);
                    exist[it->val] = adj;
                }
                b->neighbors.push_back(adj);
                if (!vis[it->val]) {
                    vis[it->val] = 1;
                    q.push(make_pair(it, adj));
                }
            }
        }
        return root;
    }
};
