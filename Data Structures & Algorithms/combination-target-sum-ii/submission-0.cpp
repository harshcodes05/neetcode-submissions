class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combo;
        backtrack(candidates, target, 0, combo, res);
        return res;
    }
    void backtrack(vector<int>& arr, int target, int idx, vector<int>& combo,
                   vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if (target - arr[i] < 0)
                break;
            if(i > idx && arr[i] == arr[i-1]) continue;
            combo.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, combo, res);
            combo.pop_back();
        }
    }
};
