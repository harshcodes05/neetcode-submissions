class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> parts;
        backtrack(s, res, parts, 0);
        return res;
    }
    bool palindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<=j)     
            if(s[i++] != s[j--]) return false;
        return true;
    }
    void backtrack(string& s, vector<vector<string>>& res, vector<string>& parts, int start) {
        if(start == s.size()) {
            res.push_back(parts);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            string valid = s.substr(start, i-start + 1);
            if(palindrome(valid)) {
                parts.push_back(valid);
                backtrack(s, res, parts, i+1);
                parts.pop_back();
            }
        }
    }
};
