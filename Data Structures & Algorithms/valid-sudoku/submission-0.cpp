class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> st;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (st.count(board[r][c])) return false;
                st.insert(board[r][c]);
            }
        }
        for (int r = 0; r < 9; r++) {
            unordered_set<char> st;
            for (int c = 0; c < 9; c++) {
                if (board[c][r] == '.') continue;
                if (st.count(board[c][r])) return false;
                st.insert(board[c][r]);
            }
        }
        for (int i = 0; i < 9; i++) {
            int row = (i / 3) * 3;
            int col = (i % 3) * 3;
            unordered_set<char> st;
            for (int r = row; r < row + 3; r++) {
                for (int c = col; c < col + 3; c++) {
                    if (board[r][c] == '.') continue;
                    if (st.count(board[r][c])) return false;
                    st.insert(board[r][c]);
                }
            }
        }

        return true;
    }
};