class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         if(s1.size()>s2.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<int> h1(26,0), h2(26,0);
        for(int i = 0; i < n; i++) h1[s1[i]-'a']++;
        for(int i = 0; i < n; i++) h2[s2[i]-'a']++;
        if(h1 == h2) return true;
        for(int i = n; i < m; i++) {
            h2[s2[i]-'a']++;
            h2[s2[i-n]-'a']--;
            if(h1==h2) return true;
        }
        return false;
    }
};
