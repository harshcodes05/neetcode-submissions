class Solution {
public:
    int maxProfit(vector<int>& p) {
        int i = 0, j = 1;
        int maxp = 0;
        while( j < p.size()) {
            maxp = max(maxp, p[j]-p[i]);
            if(p[j]<p[i]) i = j;
            j++; 
        }
        return maxp;
    }
};
