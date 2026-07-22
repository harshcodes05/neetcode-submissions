class Solution {
private:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>>& b) {
        vis[r][c] = true;
        for (auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < b.size() && nc >= 0 && nc < b[0].size() &&
                !vis[nr][nc] && b[nr][nc] != 'X')
                dfs(nr, nc, vis, b);
        }
    }

public:
    void solve(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int c = 0; c < n; c++) {
            if (b[0][c] == 'O')
                dfs(0, c, vis, b);
            if (b[m - 1][c] == 'O')
                dfs(m - 1, c, vis, b);
        }
        for (int r = 0; r < m; r++) {
            if (b[r][0] == 'O')
                dfs(r, 0, vis, b);
            if (b[r][n - 1] == 'O')
                dfs(r, n - 1, vis, b);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && b[i][j] == 'O')
                    b[i][j] = 'X';
            }
        }
    }
};
