class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mnt = 0;
        int fresh = 0;
        queue<pair<int, int>> org;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    org.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!org.empty()) {
            mnt++;
            for(int i = org.size(); i > 0; i--) {
                auto [r,c] = org.front();
                org.pop();
                for(int j = 0; j < 4; j++) {
                    int nr = r+dir[j][0];
                    int nc = c+dir[j][1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1) {
                        org.push({nr,nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }
        }
        return fresh>0?-1:max(0,mnt-1);
    }
};
