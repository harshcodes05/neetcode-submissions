class Solution {
vector<vector<int>> res;
public:
    void backT(vector<int>& nums, int idx, vector<int> ans) {
        res.push_back(ans);
        for(int i = idx; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            backT(nums, i+1, ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backT(nums, 0, {});
        return res;
    }
};
