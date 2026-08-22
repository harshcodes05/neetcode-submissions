class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dis(n, INT_MAX);
        vector<int> vis(n, 0);
        int e = 0, res = 0;
        int u = 0;
        while (e < n - 1) {
            int v = -1;
            vis[u] = 1;
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                int d = abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]);
                dis[i] = min(d, dis[i]);
                if (v == -1 || dis[i] < dis[v]) v = i;
            }
            res += dis[v];
            u = v;
            e++;
        }
        return res;
    }
};
