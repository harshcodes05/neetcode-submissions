class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int day = 0;
            for(int j = i+1; j<n; j++) {
                day++;
                if(temperatures[i]<temperatures[j]) {
                    res[i] = day;
                    break;    
                }
            } 
        }
        return res;
    }
};
