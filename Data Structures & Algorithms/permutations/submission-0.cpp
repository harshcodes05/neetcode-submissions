class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> st;
        vector<vector<int>> res;
        vector<int> perms;
        backtrack(nums, res, perms, st);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& perms, unordered_set<int> st) {
        if(perms.size() == nums.size()) {
            res.push_back(perms);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(st.count(i)) continue;
            st.insert(i);
            perms.push_back(nums[i]);
            backtrack(nums, res, perms, st);
            st.erase(i);
            perms.pop_back();
        }
    }
};
