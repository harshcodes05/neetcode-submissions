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
        int fin = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            fin++;
            for(int i: adj[node]) {
                indeg[i]--;
                if(indeg[i] == 0)
                   q.push(i);
            }
        }
        return (fin == nc);
    }
};
