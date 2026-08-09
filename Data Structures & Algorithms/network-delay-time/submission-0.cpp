class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        minH.push({0,k});
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto e: times) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        while(!minH.empty()) {
            auto [d, node] = minH.top();
            minH.pop();
            if(d > dist[node]) continue;
            for(auto nei: adj[node]) {
                auto [v, wt] = nei;
                if(d+wt < dist[v]) {
                    dist[v] = d+wt;
                    minH.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
