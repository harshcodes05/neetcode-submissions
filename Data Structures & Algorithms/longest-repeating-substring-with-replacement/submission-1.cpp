class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxF = 0;
        unordered_map<char, int> mp;
        int sh = 0, ex = 0;
        while(ex < s.size()) {
            mp[s[ex]]++;
            maxF = max(mp[s[ex]], maxF);
            if((ex-sh+1)-maxF <= k) maxLen = max(maxLen, ex-sh+1);
            else {
                mp[s[sh]]--;
                sh++;
            }
            ex++;
        }
        return maxLen;
    }
};
