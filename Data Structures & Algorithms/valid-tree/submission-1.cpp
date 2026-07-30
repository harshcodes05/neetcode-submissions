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
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = 1;
        while(!q.empty()) {
            auto [u,v] = q.front();
            q.pop();
            for(int nei: adj[u]) {
                if(nei == v) continue;
                else if(vis[nei]) return false;
                q.push({nei,u});
                vis[nei] = 1;
            }
        }
        for(int i = 0; i < n; i++)
            if(!vis[i]) return false;
        return true;
    }
};
