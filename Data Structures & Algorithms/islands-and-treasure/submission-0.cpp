class Solution {
   private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int r, int c, int dis) {
        grid[r][c] = dis;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                grid[nr][nc] > dis + 1)
                dfs(grid, nr, nc, dis + 1);
        }
    }

   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) dfs(grid, i, j, 0);
            }
        }
    }
};
