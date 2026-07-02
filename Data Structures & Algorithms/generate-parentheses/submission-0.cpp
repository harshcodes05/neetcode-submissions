class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(res, s, n, 0, 0);
        return res;
    }
    void backtrack(vector<string>& res, string& s, int n, int open, int close) {
        if(open == n and close == n) {
            res.push_back(s);
            return;
        }
        if(open < n) {
            s += '(';
            backtrack(res, s, n, open+1, close);
            s.pop_back();
        }
        if(close < open) {
            s += ')';
            backtrack(res, s, n, open, close+1);
            s.pop_back();
        }
    }
};
