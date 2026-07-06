class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        unordered_set<int> col, posd, negd;
        vector<string> board(n, string(n,'.'));
        place(0,board,res,n, col, posd, negd);
        return res;
    }
    void place(int idx, vector<string>& board, vector<vector<string>>& res, int queens, unordered_set<int> col, unordered_set<int> posd, unordered_set<int> negd) {
        if(queens == 0) {
            res.push_back(board);
            return;
        }
        if(idx>=board.size()) return;
        for(int i = 0; i < board[idx].size(); i++) {
            if(valid(col, posd, negd, idx, i)) {
                col.insert(i);
                posd.insert(idx - i);
                negd.insert(idx + i);
                board[idx][i] = 'Q';
                place(idx+1, board, res, queens-1, col, posd, negd);
                board[idx][i] = '.';
                col.erase(i);
                posd.erase(idx - i);
                negd.erase(idx + i);
            }
        }
    }
    bool valid(unordered_set<int>& col, unordered_set<int>& posd, unordered_set<int>& negd, int row, int colm) {
        if(col.count(colm) || posd.count(row-colm) || negd.count(row+colm))
            return false;
        return true;
    }
};
