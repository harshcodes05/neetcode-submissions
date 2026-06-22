class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int i : stones) maxH.push(i);
        while(maxH.size()>1) {
            int x = maxH.top();
            maxH.pop();
            int y = maxH.top();
            maxH.pop();
            if(x==y) {
                if(maxH.size()==0) maxH.push(0);
                continue;
            }
            maxH.push(abs(x-y));
        }
        return maxH.top();
    }
};
