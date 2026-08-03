class Solution {
private:
    class DisjointSet {
        vector<int> rank, ulp;
    public:
        DisjointSet(int n) {
            rank.resize(n+1,0);
            ulp.resize(n+1);
            for(int i = 0; i <= n; i++) {
                ulp[i] = i;
            }
        }
        int findUlp(int node) {
            if(ulp[node] == node) 
                return node;
            return ulp[node] = findUlp(ulp[node]);
        }
        void UnionbyRank(int u, int v) {
            int ulp_u = findUlp(u);
            int ulp_v = findUlp(v);

            if(ulp_u == ulp_v) return;
            else if(rank[ulp_u] < rank[ulp_v])
                ulp[ulp_u] = ulp_v;
            else {
                ulp[ulp_v] = ulp_u;
                if(rank[ulp_u] == rank[ulp_v])
                    rank[ulp_u]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size());
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.findUlp(u) == ds.findUlp(v))
                return {u,v};
            ds.UnionbyRank(u,v);
        }
        return {};
    }
};