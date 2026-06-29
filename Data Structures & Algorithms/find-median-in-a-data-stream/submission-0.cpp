class MedianFinder {
priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if(minH.size()>maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if((maxH.size() + minH.size())%2 == 0) return (maxH.top()+minH.top())/2.0;
        return maxH.top();
        
    }
};
