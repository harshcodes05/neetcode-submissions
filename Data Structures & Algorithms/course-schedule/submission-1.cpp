class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pre) {
        vector<vector<int>> adj(nc);
        vector<int> indeg(nc, 0);
        for(int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < nc; i++) {
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int> vis(nc, 0);
        vector<int> order;
        while(!q.empty()) {
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(int i: adj[node]) {
                indeg[i]--;
                if(!vis[i] && indeg[i] == 0)
                   q.push(i);
            }
            order.push_back(node);
        }
        return (order.size() == nc);
    }
};
