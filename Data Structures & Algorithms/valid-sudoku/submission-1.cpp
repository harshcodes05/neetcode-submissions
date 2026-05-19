class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};
        
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') continue;
                int val = int(board[r][c])-1;
                int mask = 1<<val;

                if(row[r] & mask || col[c] & mask || box[(r/3)*3 + (c/3)] & mask)
                    return false;
                
                row[r] |= mask;
                col[c] |= mask;
                box[(r/3)*3 + (c/3)] |= mask; 
            }
        }
        return true;
    }
};