class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int c = 0;
        bool tree = detect(adj, vis, 0, -1, c);
        if(c != n) return false;
        return tree;
    }
    bool detect(vector<vector<int>> &adj, vector<int> &vis, int node, int parent, int &c) {
        vis[node] = 1;
        c++;
        for(int nei: adj[node]) {
            if(nei == parent) continue;
            if(vis[nei]) return false;
            if(!detect(adj, vis, nei, node, c)) return false;
        }
        return true;
    }
};
