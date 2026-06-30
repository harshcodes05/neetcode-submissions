class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        backT(nums, 0, subset, res);
        return res;
    }
    void backT(vector<int>& nums, int idx, vector<int> subs, vector<vector<int>>& res) {
        res.push_back(subs);
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i]==nums[i-1]) continue;
            subs.push_back(nums[i]);
            backT(nums, i+1, subs, res);
            subs.pop_back();
        }
    }
};
