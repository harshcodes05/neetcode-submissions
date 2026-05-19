class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> st(nums.begin(),nums.end());
        auto it = st.begin();
        int prev = *it;
        it++;
        int c = 1,cnt = 1;
        for(;it!=st.end(); it++) {
            if(prev +1 == (*it)) {
                c++;
                cnt = max(cnt,c); 
            }
            else c = 1;
            prev = *it;
        }
        cnt = max(cnt,c); 
        return cnt;
    }
};
