class Solution {
public:
    vector<string> letterCombinations(string digit) {
        if(digit.size() == 0 ) return {};
        string num = digit;
        int i = 0, j = num.size()-1;
        while(i <= j) swap(num[i++], num[j--]);
        int n = stoi(num);
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
        string combo;
        recurse(n, mp, res, combo);
        return res;
    }
    void recurse(int num, unordered_map<int, string>& mp, vector<string>& res, string& combo) {
        if(num == 0) {
            res.push_back(combo);
            return;
        }
        string letter = mp[num%10];
        for(char c: letter) {
            combo += c;
            recurse(num/10, mp, res, combo);
            combo.pop_back();
        }
    }
};
