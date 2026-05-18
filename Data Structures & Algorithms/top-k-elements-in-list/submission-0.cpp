class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freq;
        unordered_map<int,int> mp;
        for(int i: nums) {
            mp[i]++;
        }
        for(auto it:mp) {
            freq.push_back(make_pair(it.first,it.second));
        }
        sort(freq.begin(), freq.end(),[](const auto& a, const auto& b){
            return a.second>b.second;
        });
        int j = 0;
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(freq[j++].first);
        }
        return res;
    }
};
