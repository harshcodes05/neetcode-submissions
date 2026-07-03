class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (backtrack(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j,
                   int idx) {
        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() ||
            board[i][j] != word[idx] || board[i][j] == '#')
            return false;
        char c = board[i][j];
        board[i][j] = '#';

        bool match = backtrack(board, word, i, j + 1, idx + 1) ||
                     backtrack(board, word, i + 1, j, idx + 1) ||
                     backtrack(board, word, i, j - 1, idx + 1) ||
                     backtrack(board, word, i - 1, j, idx + 1);
        board[i][j] = c;
        return match;
    }
};
