class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pf = 1, sf = 1;
        vector<int> prefix,sufix,ans;
        int j = n-1;
        for(int i = 0; i < n; i++) {
            if(i>0)pf *= nums[i-1];
            if(j<n-1) sf *= nums[j+1];
            prefix.push_back(pf);
            sufix.push_back(sf);
            j--;
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(prefix[i]*sufix[n-i-1]);
        }
        return ans;
    }
};
