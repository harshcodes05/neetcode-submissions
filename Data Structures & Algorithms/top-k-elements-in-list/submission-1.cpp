class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        for (auto& [num,freq] : mp) {
            bucket[freq].push_back(num);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
            for(int num: bucket[i])
                res.push_back(num);
        }
        return res;
    }
};
