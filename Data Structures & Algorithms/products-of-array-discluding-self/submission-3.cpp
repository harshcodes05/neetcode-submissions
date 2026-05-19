class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool flag = false;
        int c = 0;
        vector<int> ans(nums.size(), 0);
        for (int i : nums) {
            if (i == 0) {
                c++;
                if(c==2) 
                    return ans;
                flag = true;
                continue;
            }
            prod *= i;
        }
        vector<int> res(nums.size());
        if (flag) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)
                    res[i] = prod;
                else
                    res[i] = 0;
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};
