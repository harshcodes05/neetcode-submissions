class Solution {
public:
    int binSearch(vector<int> &nums, int i, int j) {
        if(i==j) return nums[i];
        int m = (i+j)/2;
        int a = binSearch(nums,i,m);
        int b = binSearch(nums, m+1,j);
        return a>b?b:a;
    }
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size()-1;
        return binSearch(nums, i, j);
    }
};
