class KthLargest {
priority_queue<int, vector<int>, greater<int>> minH;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int a: nums) {
            minH.push(a);
            if(minH.size()>k) minH.pop();
        }
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size()>k) minH.pop();
        return minH.top();
    }
};
