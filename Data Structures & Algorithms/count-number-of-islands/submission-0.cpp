class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        if(c+1<grid[r].size() && grid[r][c+1] == '1')
            dfs(grid, r, c+1);
        if(r+1<grid.size() && grid[r+1][c] == '1')
            dfs(grid, r+1, c);
        if(c-1>=0 && grid[r][c-1] == '1')
            dfs(grid, r, c-1);
        if(r-1>=0 && grid[r-1][c] == '1')
            dfs(grid, r-1, c);   
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};
