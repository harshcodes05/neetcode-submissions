class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int s = 0, e = (n*m)-1;
        while(s<=e) {
            int mid = (s+e)/2;
            int r = mid/m, c = mid%m;
            int num = matrix[r][c];
            if(num==target) return true;
            else if(num<target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }
};
