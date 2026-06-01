class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b;
        for(const string &s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                b = st.top(); st.pop();
                a = st.top(); st.pop();
                if(s == "+") st.push(a+b);
                else if(s == "-") st.push(a-b);
                else if(s == "*") st.push(a*b);
                else st.push(a/b);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
