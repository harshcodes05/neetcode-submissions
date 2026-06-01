class MinStack {
    stack<int> st, minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minst.push(min(val, minst.empty()?val:minst.top()));
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
