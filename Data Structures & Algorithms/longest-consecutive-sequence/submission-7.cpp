class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int num: nums) {
            if(!st.count(num-1)) {
                int length = 1;
                while(st.count(num+length)) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
