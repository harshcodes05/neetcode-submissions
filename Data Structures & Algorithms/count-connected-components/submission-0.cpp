class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<int>& vis, int node) {
        vis[node] = 1;
        for(int nei: adj[node]) {
            if(!vis[nei]) dfs(adj, vis, nei);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int c = 0;
        vector<vector<int>> adj(n);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                c++;
                dfs(adj, vis, i);
            }
        }
        return c;
    }
};
