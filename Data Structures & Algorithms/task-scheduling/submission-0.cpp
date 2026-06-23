class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int freq = INT_MIN, cnt = 0;
        for (auto c : tasks) {
            mp[c]++;
            if (freq < mp[c]) {
                freq = mp[c];
                cnt = 1;
            } else if (freq == mp[c])
                cnt++;
        }
        int ans = max((((freq - 1) * (n+1)) + cnt), (int)tasks.size());
        return ans;
    }
};
