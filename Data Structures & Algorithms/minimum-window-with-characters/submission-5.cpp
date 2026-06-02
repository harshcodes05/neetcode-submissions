class Solution {
   public:
    string minWindow(string s, string t) {
         int hash[256] = {0};
        int n = s.size(), m = t.size();
        for(int i = 0; i < m ; i++) 
            hash[t[i]]++;
        int s_idx = -1, minLen = INT_MAX, c = 0;
        int l = 0, r = 0; 
        while(r < n) {
            if(hash[s[r]]>0)
                c++;
            hash[s[r]]--;
            while(c == m) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    s_idx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) 
                    c--;
                l++;
            }
            r++;
        }
        return s_idx == -1? "" : s.substr(s_idx, minLen);
    }
};
