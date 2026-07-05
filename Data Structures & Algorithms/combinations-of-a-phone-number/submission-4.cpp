class Solution {
public:
    vector<string> letterCombinations(string digit) {
        if(digit.size() == 0 ) return {};
        vector<string> combo = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        recurse(0, "", res, combo, digit);
        return res;
    }
    void recurse(int idx, string curr, vector<string>& res, vector<string>& combo, string& digit) {
        if(curr.size() == digit.size()) {
            res.push_back(curr);
            return;
        }
        string letter = combo[digit[idx]-'0'];
        for(char c: letter) {
            recurse(idx+1, curr+c, res, combo, digit);
        }
    }
};
