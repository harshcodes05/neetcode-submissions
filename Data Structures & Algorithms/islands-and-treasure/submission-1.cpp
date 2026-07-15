class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> cell;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) cell.push(make_pair(i,j));
            }
        }
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!cell.empty()) {
            auto [r, c] = cell.front();
            cell.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]>grid[r][c]+1) {
                    cell.push(make_pair(nr, nc));
                    grid[nr][nc] = grid[r][c]+1;
                }
            }
        }
    }
};
