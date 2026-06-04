class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        int maxA = 0;
        stack<pair<int,int>> st;
        int l;
        for(int i = 0; i <= n; i++) {
            int l = i;
            int h = (i<n)?heights[i]:0;
            while(!st.empty() && h<st.top().second) {
                l = st.top().first;
                int ch = st.top().second;
                maxA = max(maxA, ch*(i-l));
                st.pop();
            }
            st.push(make_pair(l,h));
        }
        return maxA;
    }
};
