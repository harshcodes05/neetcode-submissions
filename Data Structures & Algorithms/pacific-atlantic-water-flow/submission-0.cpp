class Solution {
private:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int r, int c, vector<vector<bool>>& oc, vector<vector<int>>& h) {
        oc[r][c] = true;
        for(auto [dr, dc]: dir) {
            int nr = r+dr, nc = c+dc;
            if(nr>=0 && nc>=0 && nr<h.size() && nc<h[0].size() && !oc[nr][nc] && h[r][c]<=h[nr][nc])
                dfs(nr, nc, oc, h);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false)), atl(n, vector<bool>(m, false));

        for(int c = 0; c < m; c++) {
            dfs(0, c, pac, h);
            dfs(n-1, c, atl, h);
        }
        for(int r = 0; r < n; r++) {
            dfs(r, 0, pac, h);
            dfs(r, m-1, atl, h);
        }
        vector<vector<int>> res;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(pac[r][c] && atl[r][c])
                    res.push_back({r,c});
            }
        }
        return res;
    }
};
