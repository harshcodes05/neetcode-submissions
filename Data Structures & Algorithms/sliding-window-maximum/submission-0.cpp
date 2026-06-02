class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        int c = 0;
        for(int i = 0; i < n; i++) {
            c++;
            mp[nums[i]]++;
            if(c<k) continue;
            ans.push_back(prev(mp.end())->first);
            mp[nums[i-k+1]]--;
            if(mp[nums[i-k+1]] == 0) mp.erase(nums[i-k+1]);
        }
        return ans;
    }
};
