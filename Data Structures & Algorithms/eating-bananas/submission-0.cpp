class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        for(int i: piles) sum += i;
        long long s = 1, e = sum;
        while(s<=e) {
            long long m = (e-s)/2+s;
            long long k = 0;
            for(int i:piles) {
                if(i%m) k += (m+i)/m;
                else k += i/m;
            }
            if(k<=(long long)h) e = m-1;
            else s = m+1;
        }
        return (int)s;
    }
};
