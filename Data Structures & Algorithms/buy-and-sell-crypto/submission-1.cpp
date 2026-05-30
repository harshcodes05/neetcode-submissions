class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0, p = 0;
        while(r<prices.size()) {
            if(prices[l]>prices[r]) l++;
            else {
                p=prices[r]-prices[l];
                maxP = max(maxP,p);
                r++;
            }
        }
        return maxP;
    }
};
