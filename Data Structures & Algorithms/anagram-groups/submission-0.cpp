class Solution {
public:
    bool helper(string s, string t) {
        if(s.size()!=t.size()) return false;
        int map[26] = {0};
        for(char c:s){
            map[c-'a']++;
        }
        for(char c:t){
            map[c-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(map[i]!=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp(strs);
        vector<vector<string>> res;
        int j = 0;
        while(temp.size()>0) {
            res.resize(res.size()+1);
            string s = temp[0];
            temp.erase(temp.begin());
            res[j].push_back(s);
            for(int i = 0; i < temp.size();) {
                string t = temp[i];
                if(helper(s,t)) {
                    res[j].push_back(t);
                    temp.erase(temp.begin()+i);
                } else i++;
            }
            j++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
