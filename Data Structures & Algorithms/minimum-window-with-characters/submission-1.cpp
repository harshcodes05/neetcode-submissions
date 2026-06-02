class Solution {
   public:
    string minWindow(string s, string t) {
        string res = "";
        if (s.size() < t.size()) return res;
        vector<int> h1(52, 0);
        for (int i = 0; i < t.size(); i++) {
            h1[islower(t[i]) ? t[i] - 'a' : t[i] - 'A' + 26]++;
        }
        for(int i = 0; i < s.size(); i++) {
            vector<int> h2(52,0);
            string temp = "";
            for(int j = i; j < s.size(); j++) {
                temp += s[j];
                h2[islower(s[j]) ? s[j] - 'a' : s[j] - 'A' + 26]++;
                int f = 1;
                for(int k = 0; k < 52; k++) {
                    if(h1[k]==0) continue;
                    if(h1[k] > h2[k]) {
                        f = 0;
                        break;
                    }
                }
                if(f) {
                    if(res.empty() || res.size()>temp.size())
                    res = temp;
                }
            }
        }
        return res;
    }
};
