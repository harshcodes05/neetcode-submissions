class Solution {
   public:
    string minWindow(string s, string t) {
        string res = "";
        if (s.size() < t.size()) return res;
        vector<int> h1(52, 0), h2(52, 0);
        for (int i = 0; i < t.size(); i++) {
            h1[islower(t[i]) ? t[i] - 'a' : t[i] - 'A' + 26]++;
        }
        int l = 0, r = 0;
        int f2 = 1;
        while (r < s.size()) {
            if(f2)h2[islower(s[r]) ? s[r] - 'a' : s[r] - 'A' + 26]++;
            int f = 1;
            for (int k = 0; k < 52; k++) {
                if (h1[k] == 0) continue;
                if (h1[k] > h2[k]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                string temp = s.substr(l,r-l+1);
                if (res.empty() || res.size() > temp.size())   
                    res = temp;
                if(res.size() == 1) return res;
                h2[islower(s[l]) ? s[l] - 'a' : s[l] - 'A' + 26]--;
                l++;
                f2 = 0;
            }
            else f2 = 1,r++;
        }
        return res;
    }
};
