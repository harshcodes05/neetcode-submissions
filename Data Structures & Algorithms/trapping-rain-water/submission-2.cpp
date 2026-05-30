class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, l = 0, r = height.size()-1;
        int left =  height[l], right = height[r];
        while(l<r) {
            if(left<right) {
                l++;
                left = max(left,height[l]);
                sum += (left - height[l]);
            }
            else {
                r--;
                right = max(right,height[r]);
                sum += (right-height[r]);
            }
        }
        return sum;
    }
};
