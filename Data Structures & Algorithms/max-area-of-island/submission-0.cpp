class Solution {
private:
    int adj[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int area(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int ar = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r+adj[i][0];
            int nc = c+adj[i][1];
            if(nr >= 0 && nc >= 0 && nr < (int)grid.size() && nc < (int)grid[0].size() && !vis[nr][nc] && grid[nr][nc]) 
                ar += area(grid, nr, nc, vis); 
        }
        return ar;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxA = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) 
                    maxA = max(maxA, area(grid, i, j, vis));
            }
        }
        return maxA;
    }
};
