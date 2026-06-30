class Solution {
public:
     void backtrack(vector<int>& arr, int target, int idx, vector<int>& combo,
                   vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(combo);
            return;
        }
        if (idx >= arr.size() || target < 0)
            return;
        combo.push_back(arr[idx]);
        backtrack(arr, target - arr[idx], idx, combo, res);
        combo.pop_back();
        backtrack(arr, target, idx + 1, combo, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combo;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, combo, res);
        return res;
    }
};
