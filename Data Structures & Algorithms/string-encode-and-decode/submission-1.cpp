class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for(const string& s: strs) {
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        int idx = 0;
        vector<string> res;
        while(i<s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j));
            res.resize(res.size()+1);
            res[idx++] = s.substr(j+1,len);
            i = j + len + 1;
        }
        return res;
    }
};
