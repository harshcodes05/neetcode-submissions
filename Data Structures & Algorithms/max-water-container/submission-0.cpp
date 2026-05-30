class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n-1;
        int max_area = 0;
        while(l<r) {
            int area = min(heights[l],heights[r]) * (r-l);
            max_area = max(area, max_area);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return max_area;
    }
};
